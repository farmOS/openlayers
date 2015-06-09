Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control.internal.zoomtoextent',
  init: function(data) {
    return new ol.control.ZoomToExtent(data.opt);
  }
});
