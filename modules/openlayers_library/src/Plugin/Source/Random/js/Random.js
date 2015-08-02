Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source:Random',
  init: function(data) {

    var randomProperty = function (obj) {
      var keys = Object.keys(obj);
      return obj[keys[ keys.length * Math.random() << 0]];
    };

    var count = data.opt.count;
    var features = new Array(count);
    var e = 9000000;
    for (var i = 0; i < count; ++i) {
      var coordinates = [2 * e * Math.random() - e, 2 * e * Math.random() - e];
      features[i] = new ol.Feature(new ol.geom.Point(coordinates));
      if (data.opt.setRandomStyle === 1) {
        var style = randomProperty(data.opt.style);
        if (goog.isDef(data.objects.styles[style])) {
          if (typeof data.objects.styles[style] === 'function') {
            style = data.objects.styles[style](features[i]);
          } else {
            style = data.objects.styles[style];
          }
          features[i].setStyle(style);
        }
      }
    }

    var options = {
      features: features
    };

    return new ol.source.Vector(options);
  }
});
