Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source.internal.kml',
  init: function(data) {
    data.opt.format = new ol.format.KML({
      extractStyles: false
    });
    return new ol.source.Vector(data.opt);
  }
});
