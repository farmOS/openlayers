Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Layer.internal.Heatmap',
  init: function(data) {
    return new ol.layer.Heatmap(data.opt);
  }
});
