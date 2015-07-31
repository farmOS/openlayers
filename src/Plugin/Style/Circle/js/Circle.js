Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Style:Circle',
  init: function(data) {
    return function (feature, resolution) {
      var geometry = feature.getGeometry().getType();
      if (goog.isDef(data.opt[geometry])) {
        var geometry_style = data.opt[geometry];
      }else {
        var geometry_style = data.opt['default'];
      }
      return [
        new ol.style.Style({
          image: new ol.style.Circle({
            fill: new ol.style.Fill({
              color: 'rgba(' + geometry_style.image.fill.color + ')'
            }),
            stroke: new ol.style.Stroke({
              width: data.opt.stroke.width,
              color: 'rgba(' + geometry_style.image.stroke.color + ')'
            }),
            radius: geometry_style.image.radius
          }),
          fill: new ol.style.Fill({
            color: 'rgba(' + geometry_style.fill.color + ')'
          }),
          stroke: new ol.style.Stroke({
            width: geometry_style.stroke.width,
            color: 'rgba(' + geometry_style.stroke.color + ')'
          })
        })
      ];
    };
  }
});
