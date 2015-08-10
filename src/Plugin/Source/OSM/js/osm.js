Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source:OSM',
  init: function(data) {
    return new ol.source.OSM(data.opt);
  }
});
