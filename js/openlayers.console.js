goog.provide('Drupal.openlayers.console');

/**
 * Logging implementation that logs using the browser's logging API.
 * Falls back to doing nothing in case no such API is available. Simulates
 * the presece of Firebug's console API in Drupal.openlayers.console.
 */
(function($) {
  "use strict";
  Drupal.openlayers.console = (function($) {
    var api = {};
    var logger;
    if (goog.isObject(console) && goog.isFunction(console.log)){
      logger = function(){
        // Use console.log as fallback for missing parts of API if present.
        console.log.apply(console, arguments);
      };
    } else {
      logger = function (){
        // Ignore call as no logging facility is available.
      };
    }
    $(["log", "debug", "info", "warn", "exception", "assert", "dir","dirxml", "trace", "group", "groupEnd", "groupCollapsed", "profile","profileEnd", "count", "clear", "time", "timeEnd", "timeStamp", "table","error"]).each(function(index, functionName){
      if (!goog.isObject(console) || !goog.isFunction(console[functionName])){
        // Use fallback as browser does not provide implementation.
        api[functionName] = logger;
      } else {
        api[functionName] = function(){
          // Use browsers implementation.
          console[functionName].apply(console, arguments);
        };
      }
    });
    return api;
  })(jQuery);
})(jQuery);
