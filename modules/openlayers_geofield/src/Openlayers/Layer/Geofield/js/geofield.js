Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Layer.internal.geofield',
  init: function(data) {
    return new ol.layer.Vector(data.opt);
  }
});
