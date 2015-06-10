Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source.internal.TileJSON',
  init: function(data) {
    return new ol.source.TileJSON(data.opt);
  }
});
