Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.keyboardpan',
  init: function(data) {
    return new ol.interaction.KeyboardPan(data.opt);
  }
});
