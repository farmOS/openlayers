Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control.internal.fullscreen',
  init: function(data) {
    return new ol.control.FullScreen(data.opt);
  }
});
