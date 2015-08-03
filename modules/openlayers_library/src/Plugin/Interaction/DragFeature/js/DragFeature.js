Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction:DragFeature',
  init: function(data) {
    return new ol.interaction.DragFeature(data);
  }
});
