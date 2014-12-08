Drupal.openlayers = (function($){
  "use strict";
  return {
    processMap: function (map_id, context) {
      var settings = $.extend({}, {layer:[], style:[], control:[], interaction:[], source: [], projection:[], component:[]}, Drupal.settings.openlayers.maps[map_id]);

      $(document).trigger('openlayers.build_start', [
        {
          'type': 'objects',
          'settings': settings,
          'context': context
        }
      ]);

      try {
        $(document).trigger('openlayers.map_pre_alter', [{context: context, cache: Drupal.openlayers.cacheManager}]);
        var map = Drupal.openlayers.getObject(context, 'maps', settings.map, null);
        Drupal.openlayers.cacheManager.set(map.mn, map);
        $(document).trigger('openlayers.map_post_alter', [{map: map, cache: Drupal.openlayers.cacheManager}]);

        $(document).trigger('openlayers.sources_pre_alter', [{sources: settings.source, cache: Drupal.openlayers.cacheManager}]);
        settings.source.map(function (data) {
          if (goog.isDef(data.opt) && goog.isDef(data.opt.attributions)) {
            data.opt.attributions = [
              new ol.Attribution({
                'html': data.opt.attributions
              })
            ];
          }
          Drupal.openlayers.cacheManager.set(data.mn, Drupal.openlayers.getObjectFromCache(context, 'sources', data, map));
        });
        $(document).trigger('openlayers.sources_post_alter', [{sources: settings.source, cache: Drupal.openlayers.cacheManager}]);

        $(document).trigger('openlayers.controls_pre_alter', [{controls: settings.control, cache: Drupal.openlayers.cacheManager}]);
        settings.control.map(function (data) {
          Drupal.openlayers.cacheManager.set(data.mn, Drupal.openlayers.getObject(context, 'controls', data, map));
          map.addControl(Drupal.openlayers.cacheManager.get(data.mn));
        });
        $(document).trigger('openlayers.controls_post_alter', [{controls: settings.control, cache: Drupal.openlayers.cacheManager}]);

        $(document).trigger('openlayers.interactions_pre_alter', [{interactions: settings.interaction, cache: Drupal.openlayers.cacheManager}]);
        settings.interaction.map(function (data) {
          Drupal.openlayers.cacheManager.set(data.mn, Drupal.openlayers.getObjectFromCache(context, 'interactions', data, map));
          map.addInteraction(Drupal.openlayers.cacheManager.get(data.mn));
        });
        $(document).trigger('openlayers.interactions_post_alter', [{interactions: settings.interaction, cache: Drupal.openlayers.cacheManager}]);

        $(document).trigger('openlayers.styles_pre_alter', [{styles: settings.style, cache: Drupal.openlayers.cacheManager}]);
        settings.style.map(function (data) {
          Drupal.openlayers.cacheManager.set(data.mn, Drupal.openlayers.getObjectFromCache(context, 'styles', data, map));
        });
        $(document).trigger('openlayers.styles_post_alter', [{styles: settings.style, cache: Drupal.openlayers.cacheManager}]);

        $(document).trigger('openlayers.layers_pre_alter', [{layers: settings.layer, cache: Drupal.openlayers.cacheManager}]);
        settings.layer.map(function (data) {
          data.opt.source = Drupal.openlayers.cacheManager.get(data.opt.source);
          if (goog.isDef(data.opt.style) && goog.isDef(Drupal.openlayers.cacheManager.isRegistered(data.opt.style))) {
            data.opt.style = Drupal.openlayers.cacheManager.get(data.opt.style);
          }
          Drupal.openlayers.cacheManager.set(data.mn, Drupal.openlayers.getObject(context, 'layers', data, map));
          map.addLayer(Drupal.openlayers.cacheManager.get(data.mn));
        });
        $(document).trigger('openlayers.layers_post_alter', [{layers: settings.layer, cache: Drupal.openlayers.cacheManager}]);

        $(document).trigger('openlayers.components_pre_alter', [{components: settings.component, cache: Drupal.openlayers.cacheManager}]);
        settings.component.map(function (data) {
          Drupal.openlayers.cacheManager.set(data.mn, Drupal.openlayers.getObjectFromCache(context, 'components', data, map));
        });
        $(document).trigger('openlayers.components_post_alter', [{components: settings.component, cache: Drupal.openlayers.cacheManager}]);

        $(document).trigger('openlayers.build_stop', [
          {
            'type': 'objects',
            'cache': Drupal.openlayers.cacheManager,
            'settings': settings,
            'context': context
          }
        ]);
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
