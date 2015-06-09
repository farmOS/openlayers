Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source.internal.xyz',
  init: function(data) {
    return new ol.source.XYZ(data.opt);
  }
});
