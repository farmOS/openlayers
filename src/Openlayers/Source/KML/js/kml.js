Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.source.internal.kml',
  init: function(data) {
    data.opt.format = ol.format.KML({
      extractStyles: false
    });
    return new ol.source.Vector(data.opt);
  }
});
