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

    if (typeof data.objects.styles[data.opt.style] !== 'undefined') {
      options.style = data.objects.styles[data.opt.style];
    }

    if (typeof data.opt.multi !== 'undefined' && data.opt.multi === 1) {
      options.multi = true;
    }

    if (typeof data.opt.condition !== 'undefined') {
      options.condition = getOlEventsCondition(data.opt.condition);
    }

    if (typeof data.opt.addCondition !== 'undefined') {
      options.addCondition = getOlEventsCondition(data.opt.addCondition);
    }

    if (typeof data.opt.toggleCondition !== 'undefined') {
      options.toggleCondition = getOlEventsCondition(data.opt.toggleCondition);
    }

    return new ol.interaction.Select(options);
  }
});
