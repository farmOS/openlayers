<?php
/**
 * @file
 * Default layers from views.
 */

/**
 * Implements hook_default_layers_alter().
 */
function openlayers_views_default_layers_alter(&$layers) {
  $views = openalyers_views_get_views('openlayers_map_views');
  foreach ($views as $view_settings) {
    list($view_name, $display) = $view_settings;
    $machine_name = 'layer_map_views_' . $view_name . '_' . $display;
    // Check if the configuration for this layer was already defined or if it
    // has been modified. If so don't add it, to keep the layer exportable.
    $custom_version = ctools_export_crud_load('openlayers_layers', $machine_name);
    if (!isset($maps[$machine_name]) && empty($custom_version)) {
      $layer = new stdClass();
      $layer->api_version = 1;
      $layer->machine_name = $machine_name;
      $layer->name = 'Views Map:' . $view_name . ':' . $display;
      $layer->description = t('Layer for !link views map', array('!link' => l(t('this'), 'admin/structure/views/view/' . $view_name . '/edit/' . $display)));
      $layer->class = 'openlayers__layer__vector';
      $layer->options = array(
        'source' => 'source_map_views_' . $view_name . '_' . $display,
      );
      $layers[$layer->machine_name] = $layer;
    }
  }
}
