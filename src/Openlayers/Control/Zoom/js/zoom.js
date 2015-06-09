Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control.internal.zoom',
  init: function(data) {
    return new ol.control.Zoom(data.opt);
  }
});
