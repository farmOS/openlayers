Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control.internal.InlineJS',
  init: function(data) {
    eval(data.opt.javascript);
    return control;
  }
});
