Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source.internal.tilejson',
  init: function(data) {
    return new ol.source.TileJSON(data.opt);
  }
});
