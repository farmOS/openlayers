<?php
/**
 * @file
 * Provide default layers.
 */

/**
 * Implements hook_default_layers().
 */
function openlayers_default_layers() {
  $export = array();

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_mapquest_osm';
  $ol_layer->name = 'MapQuest OpenStreetMap';
  $ol_layer->description = 'Layer MapQuest OpenStreetMap description';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\tile';
  $ol_layer->options = array(
    'source' => 'source_mapquest_osm',
  );
  $export['layer_tile_mapquest_osm'] = $ol_layer;

  return $export;
}
