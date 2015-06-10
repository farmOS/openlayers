Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.DoubleClickZoom',
  init: function(data) {
    return new ol.interaction.DoubleClickZoom(data.opt);
  }
});
