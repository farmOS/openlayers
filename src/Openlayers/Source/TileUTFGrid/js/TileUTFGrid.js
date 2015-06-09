Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source.internal.tileutfgrid',
  init: function(data) {
    return new ol.source.TileUTFGrid(data.opt);
  }
});
