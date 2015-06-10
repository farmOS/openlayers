Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source.internal.BingMaps',
  init: function(data) {
    return new ol.source.BingMaps(data.opt);
  }
});
