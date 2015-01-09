(function($) {
  "use strict";
  var message;
  var type = null;

  $(document).on('openlayers.build_start', function(event, objects) {
    console.time('Total building time');
    console.groupCollapsed("********************* Starting building " + objects.settings.map.mn + " *********************");
  });

  $(document).on('openlayers.map_pre_alter', function(event, objects) {
    console.groupCollapsed("Building map...");
    console.time('Building map');
  });
  $(document).on('openlayers.map_post_alter', function(event, objects) {
    console.timeEnd('Building map');
    console.groupEnd();
  });
  $(document).on('openlayers.sources_pre_alter', function(event, objects) {
    console.groupCollapsed("Building sources...");
    console.time('Building sources');
  });
  $(document).on('openlayers.sources_post_alter', function(event, objects) {
    console.timeEnd('Building sources');
    console.groupEnd();
  });

  $(document).on('openlayers.controls_pre_alter', function(event, objects) {
    console.groupCollapsed("Building controls...");
    console.time('Building controls');
  });
  $(document).on('openlayers.controls_post_alter', function(event, objects) {
    console.timeEnd('Building controls');
    console.groupEnd();
  });

  $(document).on('openlayers.interactions_pre_alter', function(event, objects) {
    console.groupCollapsed("Building interactions...");
    console.time('Building interactions');
  });
  $(document).on('openlayers.interactions_post_alter', function(event, objects) {
    console.timeEnd('Building interactions');
    console.groupEnd();
  });

  $(document).on('openlayers.styles_pre_alter', function(event, objects) {
    console.groupCollapsed("Building styles...");
    console.time('Building styles');
  });
  $(document).on('openlayers.styles_post_alter', function(event, objects) {
    console.timeEnd('Building styles');
    console.groupEnd();
  });

  $(document).on('openlayers.layers_pre_alter', function(event, objects) {
    console.groupCollapsed("Building layers...");
    console.time('Building layers');
  });
  $(document).on('openlayers.layers_post_alter', function(event, objects) {
    console.timeEnd('Building layers');
    console.groupEnd();
  });

  $(document).on('openlayers.components_pre_alter', function(event, objects) {
    console.groupCollapsed("Building components...");
    console.time('Building components');
  });
  $(document).on('openlayers.components_post_alter', function(event, objects) {
    console.timeEnd('Building components');
    console.groupEnd();
  });

  $(document).on('openlayers.object_pre_alter', function(event, objects) {
    console.groupCollapsed("Loading " + objects.type + " " + objects.data.mn + '...');
    console.time('Time');

  });
  $(document).on('openlayers.object_post_alter', function(event, objects) {
    console.timeEnd('Time');
    console.groupEnd();
  });

  $(document).on('openlayers.build_stop', function(event, objects) {
    console.timeEnd('Total building time');
    console.groupEnd();
  });
})(jQuery);
