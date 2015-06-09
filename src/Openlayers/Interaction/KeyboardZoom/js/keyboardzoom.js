Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.keyboardzoom',
  init: function(data) {
    return new ol.interaction.KeyboardZoom(data.opt);
  }
});
