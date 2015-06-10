Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.PinchRotate',
  init: function(data) {
    return new ol.interaction.PinchRotate(data.opt);
  }
});
