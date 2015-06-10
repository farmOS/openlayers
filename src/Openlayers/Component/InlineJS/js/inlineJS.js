Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component.internal.InlineJS',
  init: function(data) {
    eval(data.opt.javascript);
  }
});
