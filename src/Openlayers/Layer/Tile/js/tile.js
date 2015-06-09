Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Layer.internal.tile',
  init: function(data) {
    return new ol.layer.Tile(data.opt);
  }
});
