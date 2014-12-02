Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.component.internal.setvalues',
  init: function(data) {
    data.map.on('moveend', function(evt){
      var selector = '#' + data.opt.latitude;
      jQuery(selector).val(data.map.getView().getCenter()[0]);
      var selector = '#' + data.opt.longitude;
      jQuery(selector).val(data.map.getView().getCenter()[1]);
      var selector = '#' + data.opt.rotation;
      jQuery(selector).val(Math.round(data.map.getView().getRotation() * (180 / Math.PI)));
      var selector = '#' + data.opt.zoom;
      jQuery(selector).val(data.map.getView().getZoom());
    });
  }
});
