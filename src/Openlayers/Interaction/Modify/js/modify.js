Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.Modify',
  init: function(data) {
    return new ol.interaction.Modify(data.opt);
  }
});
