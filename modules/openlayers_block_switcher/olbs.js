(function ($) {
  Drupal.behaviors.olebs =  {
    attach: function(context, settings) {

      $(".form-item-overlays input[type='checkbox']").on('change', function(e) {
        var target = $(this).closest('form').find("input[name='map']").val();
        for (objectMachineName in Drupal.openlayers.cacheManager.getCache()) {
          var map = Drupal.openlayers.cacheManager.get(objectMachineName);
          if (map.target == target) {
            var layers = map.getLayers();
            var target = $(e.target);
            layers.forEach(function(layer){
              if (layer.mn == target.val()) {
                if (target.prop('checked') == true) {
                  layer.setVisible(true);
                } else {
                  layer.setVisible(false);
                }
              }
            });
          }
        }
      });

    }
  };
})(jQuery);

