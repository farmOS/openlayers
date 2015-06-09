Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.dragrotate',
  init: function(data) {
    return new ol.interaction.DragRotate(data.opt);
  }
});
