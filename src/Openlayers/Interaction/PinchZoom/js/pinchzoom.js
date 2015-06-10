Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.PinchZoom',
  init: function(data) {
    return new ol.interaction.PinchZoom(data.opt);
  }
});
