<?php
/**
 * @file
 * Default sources from views.
 */

/**
 * Implements hook_default_sources_alter().
 */
function openlayers_views_default_sources_alter(&$sources) {
  $views = openalyers_views_get_views('openlayers_source_vector');
  foreach ($views as $view_settings) {
    list($view_name, $display) = $view_settings;
    $machine_name = 'source_views_' . $view_name . '_' . $display;
    // Check if the configuration for this source was already defined or if it
    // has been modified. If so don't add it, to keep the source exportable.
    $custom_version = ctools_export_crud_load('openlayers_sources', $machine_name);
    if (!isset($maps[$machine_name]) && empty($custom_version)) {
      if ($view = views_get_view($view_name)) {
        $view->set_display($display);

        $source = new stdClass();
        $source->api_version = 1;
        $source->machine_name = $machine_name;
        $source->name = 'Views Source: ' . $view->name . '_' . $display;
        $source->description = '';
        $source->class = 'openlayers__source__vector';
        $source->options = array(
          'url' => url($view->display_handler->get_url(), array('absolute' => TRUE)),
        );
        $sources[$source->machine_name] = $source;
      }
    }
  }

  $views = openalyers_views_get_views('openlayers_map_views');
  foreach ($views as $view_settings) {
    list($view_name, $display) = $view_settings;
    $machine_name = 'source_map_views_' . $view_name . '_' . $display;
    // Check if the configuration for this source was already defined or if it
    // has been modified. If so don't add it, to keep the source exportable.
    $custom_version = ctools_export_crud_load('openlayers_sources', $machine_name);
    if (!isset($maps[$machine_name]) && empty($custom_version)) {
      $source = new stdClass();
      $source->api_version = 1;
      $source->machine_name = $machine_name;
      $source->name = 'Views Map: ' . $view_name . ':' . $display;
      $source->description = t('Source for !link views map', array('!link' => l(t('this'), 'admin/structure/views/view/' . $view_name . '/edit/' . $display)));
      $source->class = 'openlayers__source__vector';
      $source->options = array();
      $sources[$source->machine_name] = $source;
    }
  }
}
