Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.source.internal.osm',
  init: function(data) {
    return new ol.source.OSM(data.opt);
  }
});
