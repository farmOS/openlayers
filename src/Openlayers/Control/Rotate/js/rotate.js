Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control.internal.rotate',
  init: function(data) {
    return new ol.control.Rotate(data.opt);
  }
});
