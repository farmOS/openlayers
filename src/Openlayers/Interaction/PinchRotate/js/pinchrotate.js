Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.pinchrotate',
  init: function(data) {
    return new ol.interaction.PinchRotate(data.opt);
  }
});
