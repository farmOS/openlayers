Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.dragzoom',
  init: function(data) {
    return new ol.interaction.DragZoom(data.opt);
  }
});
