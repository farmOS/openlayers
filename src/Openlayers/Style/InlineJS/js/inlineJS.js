Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Style.internal.InlineJS',
  init: function(data) {
    eval(data.opt.javascript);
    return style;
  }
});
