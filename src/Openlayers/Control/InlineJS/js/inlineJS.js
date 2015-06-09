Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control.internal.inlinejs',
  init: function(data) {
    eval(data.opt.javascript);
    return control;
  }
});
