Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.modify',
  init: function(data) {
    return new ol.interaction.Modify(data.opt);
  }
});
