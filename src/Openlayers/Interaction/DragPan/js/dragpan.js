Drupal.openlayers.openlayers_interaction_internal_dragpan = function(data) {
  // Todo: make a check on those values in js or php ?
  var kinetic = new ol.Kinetic(data.opt.decay, data.opt.minVelocity, data.opt.delay);
  return new ol.interaction.DragPan({kinetic: kinetic});
};
