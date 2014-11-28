Drupal.openlayers.openlayers_source_internal_tiledebug = function(data) {
  var options = {
    tileGrid: new ol.tilegrid.XYZ({maxZoom: data.opt.maxZoom}),
    // todo: handle projection stuff
    projection: 'EPSG:3857'
  };

  return new ol.source.TileDebug(options);
};
