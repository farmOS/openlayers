Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Style:RegularShape',
  init: function(data) {
    return function (feature, resolution) {
      var geometry = feature.getGeometry().getType();
      var geometry_style;
      if (goog.isDef(data.opt[geometry])) {
        geometry_style = data.opt[geometry];
      }else {
        geometry_style = data.opt['default'];
      }
      var options = {
        fill: new ol.style.Fill({
          color: 'rgba(' + geometry_style.image.fill.color + ')'
        }),
        stroke: new ol.style.Stroke({
          width: geometry_style.image.stroke.width,
          color: 'rgba(' + geometry_style.image.stroke.color + ')',
          lineDash: geometry_style.image.stroke.lineDash.split(',')
        })
      };

      if (goog.isDef(geometry_style.image.radius)) {
        options.radius = geometry_style.image.radius;
      }
      if (goog.isDef(geometry_style.image.points)) {
        options.points = geometry_style.image.points;
      }
      if (goog.isDef(geometry_style.image.radius1)) {
        options.radius1 = geometry_style.image.radius1;
      }
      if (goog.isDef(geometry_style.image.radius2)) {
        options.radius2 = geometry_style.image.radius2;
      }
      if (goog.isDef(geometry_style.image.angle)) {
        options.angle = geometry_style.image.angle * Math.PI / 180;
      }
      if (goog.isDef(geometry_style.image.rotation)) {
        options.rotation = geometry_style.image.rotation * Math.PI / 180;
      }
      return [
        new ol.style.Style({
          image: new ol.style.RegularShape(options),
          fill: new ol.style.Fill({
            color: 'rgba(' + geometry_style.fill.color + ')'
          }),
          stroke: new ol.style.Stroke({
            width: geometry_style.stroke.width,
            color: 'rgba(' + geometry_style.stroke.color + ')',
            lineDash: geometry_style.stroke.lineDash.split(',')
          })
        })
      ];
    };
  }
});
