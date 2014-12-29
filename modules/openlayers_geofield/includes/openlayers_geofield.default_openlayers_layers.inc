<?php
/**
 * @file
 * Default layers.
 */

/**
 * Implements hook_default_layers().
 */
function openlayers_geofield_default_openlayers_layers() {
  $export = array();


  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_geofield_layer_openstreetmap';
  $ol_layer->name = 'Geofield OpenStreetMap';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.layer.internal.Tile';
  $ol_layer->options = array(
    'source' => 'openlayers_geofield_source_openstreetmap',
  );
  $export['openlayers_geofield_layer_openstreetmap'] = $ol_layer;

  return $export;
}
