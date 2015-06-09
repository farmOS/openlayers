Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control.internal.zoomslider',
  init: function(data) {
    return new ol.control.ZoomSlider(data.opt);
  }
});
