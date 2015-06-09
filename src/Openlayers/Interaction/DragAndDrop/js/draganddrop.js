Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.draganddrop',
  init: function(data) {
    return new ol.interaction.DragAndDrop(data.opt);
  }
});
