Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.DragZoom',
  init: function(data) {
    return new ol.interaction.DragZoom(data.opt);
  }
});
