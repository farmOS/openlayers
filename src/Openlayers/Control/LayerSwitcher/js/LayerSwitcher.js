Drupal.openlayers.control__layerswitcher = function(data) {
  var element = jQuery(data.options.element);

  jQuery('input[name=layer]', element).change(function() {
    data.map.getLayers().forEach(function(layer, index, array) {
      // If this layer is exposed in the control check its state.
      if (jQuery('input[value=' + layer.machine_name + ']', element).length) {
        layer.setVisible(jQuery('input[value=' + layer.machine_name + ']', element).is(':checked'));
      }
    });
  });

  return new ol.control.Control({
    element: element[0]
  });
};
