Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control:Geofield',
  init: function(data) {
    return new ol.control.GeoField(data.opt);
  }
});


