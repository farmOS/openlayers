goog.provide('Drupal.openlayers.pluginManager');

(function($) {
  "use strict";

  Drupal.openlayers.pluginManager = (function($) {
    var plugins = [];
    return {
      attach: function(context, settings) {
        for (var i in plugins) {
          var plugin = plugins[i];
          if (goog.isFunction(plugin.attach)) {
            plugin.attach(context, settings);
          }
        }
      },
      detach: function(context, settings) {
        for (var i in plugins) {
          var plugin = plugins[i];
          if (goog.isFunction(plugin.detach)) {
            plugin.detach(context, settings);
          }
        }
      },
      alter: function(){
        // @todo: alter hook
      },
      getPlugin: function(factoryService) {
        if (this.isRegistered(factoryService)) {
          return plugins[factoryService];
        }
        return false;
      },
      getPlugins: function(){
        return Object.keys(plugins);
      },
      register: function(plugin) {
        if (!goog.isObject(plugin)) {
          return false;
        }

        if (!plugin.hasOwnProperty('fs') || !goog.isFunction(plugin.init)) {
          return false;
        }

        plugins[plugin.fs.toLowerCase()] = plugin;
      },
      createInstance: function(factoryService, data) {
        var factoryService = factoryService.toLowerCase();

        if (!this.isRegistered(factoryService)) {
          return false;
        }

        try {
          var obj = plugins[factoryService].init(data);
        } catch(e) {
          // @todo: handler here.
        }

        if (goog.isObject(obj)) {
          obj.mn = data.data.mn;
          return obj;
        }

        return false;
      },
      isRegistered: function(factoryService) {
        var factoryService = factoryService.toLowerCase();

        if (factoryService in plugins) {
          return true;
        }
        return false;
      }
    };
  })(jQuery);
})(jQuery);
