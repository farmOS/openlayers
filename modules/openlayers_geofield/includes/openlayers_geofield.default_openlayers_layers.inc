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
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_geofield_layer_formatter';
  $ol_layer->name = 'Openlayers Geofield formatter';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Vector';
  $ol_layer->options = array(
    'source' => 'geofield_field_formatter_source',
    'style' => 'openlayers_geofield_style_edit',
  );
  $export['openlayers_geofield_layer_formatter'] = $ol_layer;

  return $export;
}
