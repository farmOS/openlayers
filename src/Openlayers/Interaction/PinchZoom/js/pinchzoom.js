Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.pinchzoom',
  init: function(data) {
    return new ol.interaction.PinchZoom(data.opt);
  }
});
