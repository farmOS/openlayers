<?php
/**
 * @file
 * Provide default maps.
 */

/**
 * Implements hook_default_maps().
 */
function openlayers_default_maps() {
  $export = array();

  $ol_map = new stdClass();
  $ol_map->disabled = TRUE;
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'map_view_edit_form';
  $ol_map->name = 'Map view edit form';
  $ol_map->description = 'Map used in the the map edit form to get center, zoom';
  $ol_map->class = '\\Drupal\\openlayers\\map\\olmap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '400px',
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'contextualLinks' => 0,
    'provideBlock' => 0,
    'layers' => array(
      0 => 'layer_tile_mapquest_osm',
    ),
    'controls' => array(
      0 => 'control_rotate',
      1 => 'control_zoom',
      2 => 'control_zoomslider',
      3 => 'control_zoomtoextent',
    ),
    'interactions' => array(
      0 => 'interaction_dragpan',
      1 => 'interaction_dragrotate',
      2 => 'interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'map_edit_form_values',
      1 => 'map_edit_form_setcenter',
    ),
  );
  $export['map_view_edit_form'] = $ol_map;
  
  return $export;
}
