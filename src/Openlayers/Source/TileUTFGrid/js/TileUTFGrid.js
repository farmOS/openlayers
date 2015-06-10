Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source.internal.TileUTFGrid',
  init: function(data) {
    return new ol.source.TileUTFGrid(data.opt);
  }
});
