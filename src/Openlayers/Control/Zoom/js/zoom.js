Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control.internal.Zoom',
  init: function(data) {
    return new ol.control.Zoom(data.opt);
  }
});
