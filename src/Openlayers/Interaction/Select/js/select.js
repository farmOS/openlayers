Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.Select',
  init: function(data) {
    return new ol.interaction.Select(data.opt);
  }
});
