Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source.internal.bingmaps',
  init: function(data) {
    return new ol.source.BingMaps(data.opt);
  }
});
