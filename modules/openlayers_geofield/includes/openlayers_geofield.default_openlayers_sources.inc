<?php
/**
 * @file
 * Default sources.
 */

/**
 * Implements hook_default_sources().
 */
function openlayers_geofield_default_openlayers_sources() {
  $export = array();

  $ol_source = new stdClass();
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_geofield_source_openstreetmap';
  $ol_source->name = 'Geofield OpenStreetMap';
  $ol_source->description = 'Source OpenStreetMap description';
  $ol_source->factory_service = 'openlayers.source.internal.OSM';
  $ol_source->options = array();
  $export['openlayers_geofield_source_openstreetmap'] = $ol_source;

  return $export;
}
