Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Layer.internal.heatmap',
  init: function(data) {
    return new ol.layer.Heatmap(data.opt);
  }
});
