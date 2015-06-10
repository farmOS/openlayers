Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.MouseWheelZoom',
  init: function(data) {
    return new ol.interaction.MouseWheelZoom(data.opt);
  }
});
