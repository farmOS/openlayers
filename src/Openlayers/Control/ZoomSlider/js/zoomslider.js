Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control.internal.ZoomSlider',
  init: function(data) {
    return new ol.control.ZoomSlider(data.opt);
  }
});
