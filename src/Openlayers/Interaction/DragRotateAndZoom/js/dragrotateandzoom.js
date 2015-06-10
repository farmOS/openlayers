Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.DragRotateAndZoom',
  init: function(data) {
    return new ol.interaction.DragRotateAndZoom(data.opt);
  }
});
