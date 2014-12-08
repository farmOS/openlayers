Drupal.openlayers = (function($){
  "use strict";
  return {
    processMap: function (map_id, context) {
      var settings = Drupal.settings.openlayers.maps[map_id];
      $(document).trigger('openlayers.build_start', [
        {
          'type': 'objects',
          'settings': settings,
          'context': context
        }
      ]);

      var layers = settings.layer || [],
        styles = settings.style || [],
        controls = settings.control || [],
        interactions = settings.interaction || [],
        sources = settings.source || [],
        components = settings.component || [],
        objects = {
          sources: {},
          controls: {},
          interactions: {},
          components: {},
          styles: {},
          layers: {},
          maps: {}
        };

      try {
        $(document).trigger('openlayers.map_pre_alter', [{context: context, cache: Drupal.openlayers.cacheManager}]);
        var map = Drupal.openlayers.getObjectFromCache(context, 'maps', settings.map, null);

        $(document).trigger('openlayers.map_post_alter', [{map: map, cache: Drupal.openlayers.cacheManager}]);
        objects.maps[map.mn] = map;

        $(document).trigger('openlayers.sources_pre_alter', [{sources: sources, cache: Drupal.openlayers.cacheManager}]);
        sources.map(function (data) {
          if (goog.isDef(data.opt) && goog.isDef(data.opt.attributions)) {
            data.opt.attributions = [
              new ol.Attribution({
                'html': data.opt.attributions
              })
            ];
          }
          objects.sources[data.mn] = Drupal.openlayers.getObjectFromCache(context, 'sources', data, map);
        });
        $(document).trigger('openlayers.sources_post_alter', [{sources: sources, cache: Drupal.openlayers.cacheManager}]);

        $(document).trigger('openlayers.controls_pre_alter', [{controls: controls, cache: Drupal.openlayers.cacheManager}]);
        controls.map(function (data) {
          map.addControl(Drupal.openlayers.getObjectFromCache(context, 'controls', data, map));
        });
        $(document).trigger('openlayers.controls_post_alter', [{controls: controls, cache: Drupal.openlayers.cacheManager}]);

        $(document).trigger('openlayers.interactions_pre_alter', [{interactions: interactions, cache: Drupal.openlayers.cacheManager}]);
        interactions.map(function (data) {
          objects.interactions[data.mn] = Drupal.openlayers.getObjectFromCache(context, 'interactions', data, map);
          map.addInteraction(objects.interactions[data.mn]);
        });
        $(document).trigger('openlayers.interactions_post_alter', [{interactions: interactions, cache: Drupal.openlayers.cacheManager}]);

        $(document).trigger('openlayers.styles_pre_alter', [{styles: styles, cache: Drupal.openlayers.cacheManager}]);
        styles.map(function (data) {
          objects.styles[data.mn] = Drupal.openlayers.getObjectFromCache(context, 'styles', data, map);
        });
        $(document).trigger('openlayers.styles_post_alter', [{styles: styles, cache: Drupal.openlayers.cacheManager}]);

        $(document).trigger('openlayers.layers_pre_alter', [{layers: layers, cache: Drupal.openlayers.cacheManager}]);
        layers.map(function (data) {
          data.opt.source = objects.sources[data.opt.source];
          if (goog.isDef(data.opt.style) && goog.isDef(objects.styles[data.opt.style])) {
            data.opt.style = objects.styles[data.opt.style];
          }
          objects.layers[data.mn] = Drupal.openlayers.getObject(context, 'layers', data, map);
          map.addLayer(objects.layers[data.mn]);
        });
        $(document).trigger('openlayers.layers_post_alter', [{layers: layers, cache: Drupal.openlayers.cacheManager}]);

        $(document).trigger('openlayers.components_pre_alter', [{components: components, cache: Drupal.openlayers.cacheManager}]);
        components.map(function (data) {
          objects.components[data.mn] = Drupal.openlayers.getObjectFromCache(context, 'components', data, map);
        });
        $(document).trigger('openlayers.components_post_alter', [{components: components, cache: Drupal.openlayers.cacheManager}]);

        $(document).trigger('openlayers.build_stop', [
          {
            'type': 'objects',
            'objects': settings,
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
    getObject: (function (context, type, data, map) {
      var object = null;
      if (Drupal.openlayers.pluginManager.isRegistered(data['fs'])) {
        $(document).trigger('openlayers.object_pre_alter', [
          {
            'type': type,
            'mn': data.mn,
            'data': data,
            'map': map,
            'cache': Drupal.openlayers.cacheManager,
            'context': context
          }
        ]);
        object = Drupal.openlayers.pluginManager.createInstance(data['fs'], {
          'data': data,
          'opt': data.opt,
          'map': map,
          'cache': Drupal.openlayers.cacheManager,
          'context': context
        });
        $(document).trigger('openlayers.object_post_alter', [
          {
            'type': type,
            'mn': data.mn,
            'data': data,
            'map': map,
            'cache': Drupal.openlayers.cacheManager,
            'context': context
          }
        ]);
        return object;
      }
    }),
    getObjectFromCache: (function (context, type, data, map) {
      var object = null;
      if (!Drupal.openlayers.cacheManager.isRegistered(data.mn)) {
        object = this.getObject(context, type, data, map);
        Drupal.openlayers.cacheManager.set(data.mn, object);
      } else {
        $(document).trigger('openlayers.object_pre_alter', [
          {
            'type': type,
            'mn': data.mn,
            'data': data,
            'map': map,
            'cache': Drupal.openlayers.cacheManager,
            'context': context
          }
        ]);
        object = Drupal.openlayers.cacheManager.get(data.mn);
        $(document).trigger('openlayers.object_post_alter', [
          {
            'type': type,
            'mn': data.mn,
            'data': data,
            'map': map,
            'cache': Drupal.openlayers.cacheManager,
            'context': context
          }
        ]);      }
      return object;
    })
  };
})(jQuery);
