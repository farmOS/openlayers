Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Style:Random',
  init: function(data) {
    var randomProperty = function (obj) {
      var keys = Object.keys(obj);
      return obj[keys[ keys.length * Math.random() << 0]];
    };

    var style = randomProperty(data.opt.style);

    if (goog.isDef(data.objects.styles[style])) {
      return data.objects.styles[style];
    }
  }
});
