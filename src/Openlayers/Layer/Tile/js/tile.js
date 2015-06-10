Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Layer.internal.Tile',
  init: function(data) {
    return new ol.layer.Tile(data.opt);
  }
});
