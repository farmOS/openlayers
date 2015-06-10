Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control.internal.ScaleLine',
  init: function(data) {
    return new ol.control.ScaleLine(data.opt);
  }
});
