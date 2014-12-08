Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.source.internal.cluster',
  init: function(data) {
    if (data.cache.isRegistered(data.opt.source)) {
      data.opt.source = data.cache.get(data.opt.source);
      return new ol.source.Cluster(data.opt);
    }
  }
});
