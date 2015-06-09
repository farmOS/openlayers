Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.inlinejs',
  init: function(data) {
    eval(data.opt.javascript);
    return interaction;
  }
});
