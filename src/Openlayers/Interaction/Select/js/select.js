Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.select',
  init: function(data) {
    return new ol.interaction.Select(data.opt);
  }
});
