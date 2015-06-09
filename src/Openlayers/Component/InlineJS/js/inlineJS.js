Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component.internal.inlinejs',
  init: function(data) {
    eval(data.opt.javascript);
  }
});
