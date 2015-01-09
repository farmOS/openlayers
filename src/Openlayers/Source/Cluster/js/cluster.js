Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.source.internal.cluster',
  init: function(data) {
    if (goog.isDef(data.objects.sources[data.opt.source])) {
      data.opt.source = data.objects.sources[data.opt.source];
      return new ol.source.Cluster(data.opt);
    }
  }
});
