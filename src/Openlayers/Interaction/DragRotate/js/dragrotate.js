Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.DragRotate',
  init: function(data) {
    return new ol.interaction.DragRotate(data.opt);
  }
});
