Drupal.openlayers.openlayers_source_internal_kml = function(data) {
  data.opt.projection = 'EPSG:3857';
  data.opt.extractStyles = false;
  return new ol.source.KML(data.opt);
};
