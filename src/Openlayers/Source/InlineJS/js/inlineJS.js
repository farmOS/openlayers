Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source.internal.InlineJS',
  init: function(data) {
    eval(data.opt.javascript);
    return source;
  }
});
