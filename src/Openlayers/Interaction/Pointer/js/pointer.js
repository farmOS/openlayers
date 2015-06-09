Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.pointer',
  init: function(data) {
    return new ol.interaction.Pointer(data.opt);
  }
});
