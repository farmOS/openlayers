Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.layer.internal.geofield',
  init: function(data) {
    console.log(data.opt);
    return new ol.layer.Vector(data.opt);
  }
});
