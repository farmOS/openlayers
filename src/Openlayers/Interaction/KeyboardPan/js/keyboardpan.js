Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.KeyboardPan',
  init: function(data) {
    return new ol.interaction.KeyboardPan(data.opt);
  }
});
