Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction:Select',
  init: function(data) {
    if (goog.isDef(data.objects.styles[data.opt.style])) {
      var options = jQuery.extend(true, {}, data.opt);
      options.style = data.objects.styles[data.opt.style];
      return new ol.interaction.Select(options);
    }
  }
});
