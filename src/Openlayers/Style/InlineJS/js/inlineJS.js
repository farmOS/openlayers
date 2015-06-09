Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Style.internal.inlinejs',
  init: function(data) {
    eval(data.opt.javascript);
    return style;
  }
});
