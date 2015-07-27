Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Style:Circle',
  init: function(data) {
    return [
      new ol.style.Style({
        image: new ol.style.Circle({
          fill: new ol.style.Fill({
            color: 'rgba(' + data.opt.color + ')'
          }),
          stroke: new ol.style.Stroke({
            width: data.opt.stroke.width,
            color: 'rgba(' + data.opt.stroke.color + ')'
          }),
          radius: data.opt.radius
        }),
        fill: new ol.style.Fill({
          color: 'rgba(' + data.opt.color + ')'
        }),
        stroke: new ol.style.Stroke({
            width: data.opt.stroke.width,
            color: 'rgba(' + data.opt.stroke.color + ')'
          })
      })
    ];
  }
});
