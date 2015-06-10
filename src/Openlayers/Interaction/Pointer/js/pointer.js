Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.Pointer',
  init: function(data) {
    return new ol.interaction.Pointer(data.opt);
  }
});
