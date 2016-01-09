Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component:OL3Cesium',
  init: function(data) {
    new olcs.OLCesium({map: data.map}).setEnabled(true);
  }
});
