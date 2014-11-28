Drupal.openlayers.openlayers_source_internal_cluster = function(data) {

  for (source in data.cache.sources) {
    if (source === data.opt.source) {
      data.opt.source = data.cache.sources[source];
      return new ol.source.Cluster(data.opt);
    }
  }

};
