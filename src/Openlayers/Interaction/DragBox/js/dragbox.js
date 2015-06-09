Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.dragbox',
  init: function(data) {
    return new ol.interaction.DragBox(data.opt);
  }
});
