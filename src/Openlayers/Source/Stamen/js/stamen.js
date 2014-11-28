Drupal.openlayers.openlayers_source_internal_stamen = function(data) {
  console.log(data);
  return new ol.source.Stamen(data.opt);
};
