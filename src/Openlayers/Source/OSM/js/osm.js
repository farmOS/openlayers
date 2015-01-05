Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.source.internal.osm',
  init: function(data) {
    data.opt.crossOrigin = null;
    return new ol.source.OSM(data.opt);
  }
});
