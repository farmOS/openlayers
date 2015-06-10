Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control.internal.FullScreen',
  init: function(data) {
    return new ol.control.FullScreen(data.opt);
  }
});
