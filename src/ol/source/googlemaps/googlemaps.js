Drupal.openlayers.openlayers__source__googlemaps = function(data) {

  var olMapDiv = jQuery(data.map.getViewport()).parent();
  var gmapDiv = jQuery('#gmap-' + olMapDiv.attr('id'));

  var gmap = new google.maps.Map(gmapDiv[0], {
    disableDefaultUI: true,
    keyboardShortcuts: false,
    draggable: false,
    disableDoubleClickZoom: true,
    scrollwheel: false,
    streetViewControl: false,
    mapTypeId: google.maps.MapTypeId[data.options.mapTypeId] || 'roadmap'
  });
  gmapDiv.data('gmap', gmap);

  data.map.getView().on('change:center', function() {
    var center = ol.proj.transform(data.map.getView().getCenter(), 'EPSG:3857', 'EPSG:4326');
    gmap.setCenter(new google.maps.LatLng(center[1], center[0]));
  });
  data.map.getView().on('change:resolution', function() {
    gmap.setZoom(data.map.getView().getZoom());
  });

  data.map.getView().setCenter(data.map.getView().getCenter());
  data.map.getView().setZoom(data.map.getView().getZoom());

  olMapDiv[0].parentNode.removeChild(olMapDiv[0]);
  gmap.controls[google.maps.ControlPosition.TOP_LEFT].push(olMapDiv[0]);

  return new ol.source.Vector();
};

/**
 * Helper to access the gmap instance in a ol.Map.
 */
Drupal.openlayers.openlayers__source__googlemaps_get_map = function(map){
  var olMapDiv = jQuery(map.getViewport()).parent();
  return jQuery('#gmap-' + olMapDiv.attr('id')).data('gmap');
};

/**
 * Attaches the gmap API by loading the script.
 * Evaluates all google maps sources and uses the most complex set of settings.
 * Attention: It's not possible to have maps with different key, channel or
 * client parameters.
 */
Drupal.behaviors.openlayers__source__googlemaps = {
  scriptLoading: false,
  attach: function(context, settings) {
    if (typeof google === 'undefined') {
      // If a script is already loading bail out.
      if (Drupal.behaviors.openlayers__source__googlemaps.scriptLoading) {
        return;
      }
      Drupal.behaviors.openlayers__source__googlemaps.scriptLoading = true;

      var params = {
        v: 3,
        callback: 'Drupal.openlayers.openlayers__source__googlemaps_initialize'
      };

      // Collect all google API settings.
      jQuery('.openlayers.gmap-map').each(function(){
        var map_id = jQuery(this).attr('id').replace('gmap-', '');

        if (typeof Drupal.settings.openlayers.maps[map_id] !== 'undefined') {
          jQuery.each(Drupal.settings.openlayers.maps[map_id].source, function(i, source){
            if (source.class == 'openlayers__source__googlemaps') {
              if (source.options.channel) {
                params.channel = source.options.channel;
              }
              if (source.options.client) {
                params.client = source.options.client;
              }
              if (source.options.key) {
                params.key = source.options.key;
              }
              if (source.options.sensor) {
                params.sensor = 'true';
              }
            }
          });
        }
      });

      // Add the script with the collected settings.
      var script = document.createElement('script');
      script.type = 'text/javascript';
      script.src = 'https://maps.googleapis.com/maps/api/js?' + jQuery.param(params);
      document.body.appendChild(script);
    }
    else {
      // Google API already available - initialize right away.
      Drupal.openlayers.openlayers__source__googlemaps_initialize();
    }
  }
};

/**
 * Callback to initialize all google maps as soon as the gmap API is available.
 */
Drupal.openlayers.openlayers__source__googlemaps_initialize = function() {
  jQuery('.openlayers.gmap-map').each(function() {
    var map_id = jQuery(this).attr('id').replace('gmap-', '');
    Drupal.openlayers.asyncIsReadyCallbacks[map_id.replace(/[^0-9a-z]/gi, '_')]();
  });
};
