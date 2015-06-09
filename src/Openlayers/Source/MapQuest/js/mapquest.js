Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source.internal.mapquest',
  init: function(data) {
    return new ol.source.MapQuest(data.opt);
  }
});
