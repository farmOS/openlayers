Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.KeyboardZoom',
  init: function(data) {
    return new ol.interaction.KeyboardZoom(data.opt);
  }
});
