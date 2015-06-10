Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control.internal.ZoomToExtent',
  init: function(data) {
    return new ol.control.ZoomToExtent(data.opt);
  }
});
