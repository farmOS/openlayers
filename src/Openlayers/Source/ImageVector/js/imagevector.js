Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.source.internal.imagevector',
  init: function(data) {
    if (goog.isDef(data.objects.sources[data.opt.source])) {
      options.source = data.objects.sources[data.opt.source];
      return new ol.source.ImageVector(options);
    }
  }
});
