Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.dragpan',
  init: function(data) {
    var kinetic = new ol.Kinetic(data.opt.decay, data.opt.minVelocity, data.opt.delay);
    return new ol.interaction.DragPan({kinetic: kinetic});
  }
});
