Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.doubleclickzoom',
  init: function(data) {
    return new ol.interaction.DoubleClickZoom(data.opt);
  }
});
