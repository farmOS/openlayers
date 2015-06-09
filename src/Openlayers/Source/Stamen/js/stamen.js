Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source.internal.stamen',
  init: function(data) {
    return new ol.source.Stamen(data.opt);
  }
});
