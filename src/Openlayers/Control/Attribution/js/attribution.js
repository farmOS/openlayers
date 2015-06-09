Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control.internal.attribution',
  init: function(data) {
    return new ol.control.Attribution(data.opt);
  }
});
