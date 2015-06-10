Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control.internal.Attribution',
  init: function(data) {
    return new ol.control.Attribution(data.opt);
  }
});
