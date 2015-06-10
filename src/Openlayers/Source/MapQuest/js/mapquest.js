Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source.internal.MapQuest',
  init: function(data) {
    return new ol.source.MapQuest(data.opt);
  }
});
