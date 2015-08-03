Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction:Select',
  init: function(data) {
    var options = jQuery.extend(true, {}, data.opt);

    function getOlEventsCondition(type) {
      var condition = null;
      switch (type) {
        case 'never':
          condition = ol.events.condition[type];
          break;
        case 'singleClick':
          condition = ol.events.condition[type];
          break;
        case 'shiftKeyOnly':
          condition = ol.events.condition[type];
          break;
        case 'pointerMove':
          condition = ol.events.condition[type];
          break;
      }
      return condition;
    }

    if (goog.isDef(data.objects.styles[data.opt.style])) {
      options.style = data.objects.styles[data.opt.style];
    }

    if (goog.isDef(data.opt.multi) && data.opt.multi === 1) {
      options.multi = true;
    }

    if (goog.isDef(data.opt.condition)) {
      options.condition = getOlEventsCondition(data.opt.condition);
    }

    if (goog.isDef(data.opt.addCondition)) {
      options.addCondition = getOlEventsCondition(data.opt.addCondition);
    }

    if (goog.isDef(data.opt.toggleCondition)) {
      options.toggleCondition = getOlEventsCondition(data.opt.toggleCondition);
    }

    return new ol.interaction.Select(options);
  }
});
