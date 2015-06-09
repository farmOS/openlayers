Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control.internal.scaleline',
  init: function(data) {
    return new ol.control.ScaleLine(data.opt);
  }
});
