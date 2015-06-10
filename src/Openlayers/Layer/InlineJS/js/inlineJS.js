Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Layer.internal.InlineJS',
  init: function(data) {
    eval(data.opt.javascript);
    return layer;
  }
});
