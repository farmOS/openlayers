Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.mousewheelzoom',
  init: function(data) {
    return new ol.interaction.MouseWheelZoom(data.opt);
  }
});
