Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.dragrotateandzoom',
  init: function(data) {
    return new ol.interaction.DragRotateAndZoom(data.opt);
  }
});
