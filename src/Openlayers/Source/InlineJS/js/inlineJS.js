Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source.internal.inlinejs',
  init: function(data) {
    eval(data.opt.javascript);
    return source;
  }
});
