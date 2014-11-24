<?php
/**
 * @file
 * Provide default sources.
 */

/**
 * Implements hook_default_sources().
 */
function openlayers_default_sources() {
  $export = array();

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_source_mapquest_osm';
  $ol_source->name = 'MapQuest OpenStreetMap';
  $ol_source->description = 'Source MapQuest OpenStreetMap description';
  $ol_source->class = '\\Drupal\\openlayers\\Source\\MapQuest';
  $ol_source->options = array(
    'layer' => 'osm',
  );
  $export['openlayers_source_mapquest_osm'] = $ol_source;

  return $export;
}

/**
 * Implements hook_default_sources().
 *
 * @todo: Move this to the views_geojson module.
 */
function views_geojson_default_sources() {
  $sources = array();
  foreach (views_get_all_views() as $view) {
    foreach ($view->display as $display => $data) {
      $view->set_display($display);
      if (in_array($view->display_handler->get_option('style_plugin'), array('views_geojson_feed', 'views_geojson'))) {
        $ol_source = new stdClass();
        $ol_source->api_version = 1;
        $ol_source->machine_name = 'views_geojson_' . $view->name . '_' . $display;
        $ol_source->name = 'Views GeoJSON source: ' . $view->name . '_' . $display;
        $ol_source->description = 'This source is automatically generated. See View ' . $view->name . ' at display ' . $display;
        $ol_source->class = '\\Drupal\\openlayers\\Source\\GeoJSON';

        $ol_source->options = array(
          'url' => url($view->display_handler->get_url(), array('absolute' => TRUE)),
        );

        // Determine if we should use a BBox strategy.
        if ($arguments = $view->display_handler->get_option('arguments')) {
          foreach ($arguments as $id => $argument) {
            if (strpos($id, 'bbox') !== FALSE && $argument['default_argument_type'] == 'querystring') {
              if (isset($argument['default_argument_options'])) {
                $ol_source->options['useBBOX'] = TRUE;
              }
            }
          }
        }
        $sources[$ol_source->machine_name] = $ol_source;
      }
    }
  }
  return $sources;
}
