Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.DragAndDrop',
  init: function(data) {
    return new ol.interaction.DragAndDrop(data.opt);
  }
});
