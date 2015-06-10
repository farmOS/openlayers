Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source.internal.Stamen',
  init: function(data) {
    return new ol.source.Stamen(data.opt);
  }
});
