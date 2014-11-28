//@todo: Create a method that generates this automatically.
//  We can like automatically check if data.opt is not undefined
//  for all the ol types.
//  ex: data.opt = data.opt || {};
Drupal.openlayers.openlayers_control_internal_mouseposition = function(data) {
  data.opt = data.opt || {};
  data.opt.coordinateFormat = ol.coordinate.createStringXY(4);
  //options.projection = 'EPSG:4326';
  return new ol.control.MousePosition(data.opt);
};
