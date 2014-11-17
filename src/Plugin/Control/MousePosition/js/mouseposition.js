//@todo: Create a method that generates this automatically.
//  We can like automatically check if data.options is not undefined
//  for all the ol types.
//  ex: data.options = data.options || {};
Drupal.openlayers.control__mouseposition = function(data) {
  data.options = data.options || {};
  data.options.coordinateFormat = ol.coordinate.createStringXY(4);
  //options.projection = 'EPSG:4326';
  return new ol.control.MousePosition(data.options);
}
