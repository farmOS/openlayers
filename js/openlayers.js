goog.provide('Drupal.openlayers');

(function($) {
  "use strict";
  Drupal.openlayers = (function($){
    return {
      processMap: function (map_id, context) {
        if (goog.isDef(Drupal.settings.openlayers.maps[map_id])) {
          var object = Drupal.settings.openlayers.maps[map_id];
          $(document).trigger('openlayers.build_start', [
            {
              'type': 'objects',
              'objects': object,
              'context': context
            }
          ]);

          var count = 1,
            layers = object.layer || [],
            styles = object.style || [],
            controls = object.control || [],
            interactions = object.interaction || [],
            sources = object.source || [],
            components = object.component || [],
            objects = {
              sources: {},
              controls: {},
              interactions: {},
              components: {},
              styles: {},
              layers: {},
              maps: {}
            };

          object.map.opt.layers = [];
          object.map.opt.styles = [];
          object.map.opt.controls = [];
          object.map.opt.interactions = [];
          object.map.opt.components = [];

          try {
            var map = Drupal.openlayers.getObject(context, 'maps', object.map, null, count);
            objects.maps[map.mn] = map;

            count = sources.length;
            sources.map(function (data) {
              if (goog.isDef(data.opt) && goog.isDef(data.opt.attributions)) {
                data.opt.attributions = [
                  new ol.Attribution({
                    'html': data.opt.attributions
                  })
                ];
              }
              objects.sources[data.mn] = Drupal.openlayers.getObject(context, 'sources', data, map, count--);
            });

            count = controls.length;
            controls.map(function (data) {
              map.addControl(Drupal.openlayers.getObject(context, 'controls', data, map, count--));
            });

            count = interactions.length;
            interactions.map(function (data) {
              objects.interactions[data.mn] = Drupal.openlayers.getObject(context, 'interactions', data, map, count--);
              map.addInteraction(objects.interactions[data.mn]);
            });

            count = styles.length;
            styles.map(function (data) {
              objects.styles[data.mn] = Drupal.openlayers.getObject(context, 'styles', data, map, count--);
            });

            count = layers.length;
            layers.map(function (data) {
              data.opt.source = objects.sources[data.opt.source];
              if (goog.isDef(data.opt.style) && goog.isDef(objects.styles[data.opt.style])) {
                data.opt.style = objects.styles[data.opt.style];
              }
              objects.layers[data.mn] = Drupal.openlayers.getObject(context, 'layers', data, map, count--);
              map.addLayer(objects.layers[data.mn]);
            });

            count = components.length;
            components.map(function (data) {
              objects.components[data.mn] = Drupal.openlayers.getObject(context, 'components', data, map, count--);
            });

            // Attach data to map DOM object
            $(document).trigger('openlayers.build_stop', [
              {
                'type': 'objects',
                'objects': object,
                'context': context
              }
            ]);
            $('body').data('openlayers', {'objects': objects});

          } catch (e) {
            if (goog.isDef(console)) {
              Drupal.openlayers.console.log(e.message);
              Drupal.openlayers.console.log(e.stack);
            }
            else {
              $(this).text('Error during map rendering: ' + e.message);
              $(this).text('Stack: ' + e.stack);
            }
          }
        }
      },

// Holds dynamic created asyncIsReady callbacks for every map id.
// The functions are named by the cleaned map id. Everything besides 0-9a-z
// is replaced by an underscore (_).
      asyncIsReadyCallbacks: {},
      asyncIsReady: function (map_id) {
        if (goog.isDef(Drupal.settings.openlayers.maps[map_id])) {
          Drupal.settings.openlayers.maps[map_id].map.async--;
          if (!Drupal.settings.openlayers.maps[map_id].map.async) {
            $('#' + map_id).once('openlayers-map', function () {
              Drupal.openlayers.processMap(map_id, document);
            });
          }
        }
      },

      getObject: (function (context, type, data, map, count) {
        var cache = $('body').data('openlayers') || {};

        if (goog.isDef(cache.objects)) {
          cache = cache.objects;
        }
        else {
          cache.sources = [];
          cache.controls = [];
          cache.styles = [];
          cache.layers = [];
          cache.interactions = [];
          cache.components = [];
          cache.maps = [];
        }

        cache = $.extend({}, cache.objects, cache);

        $(document).trigger('openlayers.object_pre_alter', [
          {
            'type': type,
            'mn': data.mn,
            'data': data,
            'map': map,
            'cache': cache,
            'context': context,
            'count': count
          }
        ]);
        var object = null;
        if (!goog.isDef(cache[type][data.mn])) {
          // TODO: Check why layers and maps doesnt cache.
          if (Drupal.openlayers.pluginManager.isRegistered(data['fs'])) {
            object = Drupal.openlayers.pluginManager.createInstance(data['fs'], {
              'data': data,
              'opt': data.opt,
              'map': map,
              'context': context,
              'cache': cache,
            });
            if (goog.isObject(object)) {
              cache[type][data.mn] = object;
            }
          }
          else {
            console.error('Callback Drupal.openlayers.' + data.fs + ' doesn\'t exist.');
          }

        }
        else {
          object = cache[type][data.mn];
        }

        $(document).trigger('openlayers.object_post_alter', [
          {
            'type': type,
            'object': object,
            'data': data,
            'map': map,
            'cache': cache,
            'context': context,
            'count': count
          }
        ]);
        $('body').data('openlayers', {'objects': cache});
        return object;
      }),
    };
  })(jQuery);
})(jQuery);
