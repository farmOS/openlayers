Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Layer.internal.Image',
  init: function(data) {
    return new ol.layer.Image(data.opt);
  }
});
