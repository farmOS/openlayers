Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction:Select',
  init: function(data) {
    var options = jQuery.extend(true, {}, data.opt);

    if (goog.isDef(data.objects.styles[data.opt.style])) {
      options.style = data.objects.styles[data.opt.style];
    }

    if (goog.isDef(data.opt.condition)) {
      switch (data.opt.condition) {
        case 'singleClick':
          condition = ol.events.condition.singleClick;
          break;
        case 'shiftKeyOnly':
          condition = ol.events.condition.shiftKeyOnly;
          break;
        case 'pointerMove':
          condition = ol.events.condition.pointerMove;
          break;
      }
      options.condition = condition;
    }
    return new ol.interaction.Select(options);
  }
});
