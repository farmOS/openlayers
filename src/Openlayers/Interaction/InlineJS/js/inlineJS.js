Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction.internal.InlineJS',
  init: function(data) {
    eval(data.opt.javascript);
    return interaction;
  }
});
