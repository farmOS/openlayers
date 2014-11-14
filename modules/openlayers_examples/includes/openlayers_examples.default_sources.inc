<?php
/**
 * @file
 * Default sources.
 */

/**
 * Implements hook_default_sources().
 */
function openlayers_examples_default_sources() {
  $export = array();

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_mapbox_example1';
  $ol_source->name = 'MapBox example 1';
  $ol_source->description = 'Source MapBox example 1';
  $ol_source->class = 'openlayers__source__tilejson';
  $ol_source->options = array(
    'url' => 'http://api.tiles.mapbox.com/v3/examples.map-i86nkdio.jsonp',
  );
  $export['source_mapbox_example1'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_mapbox_example2';
  $ol_source->name = 'MapBox example 2';
  $ol_source->description = 'Source MapBox example 2';
  $ol_source->class = 'openlayers__source__tilejson';
  $ol_source->options = array(
    'url' => 'http://api.tiles.mapbox.com/v3/examples.c7d2024a.jsonp',
  );
  $export['source_mapbox_example2'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_mapbox_example3';
  $ol_source->name = 'MapBox example 3';
  $ol_source->description = 'Source MapBox example 3, used by ft.com.';
  $ol_source->class = 'openlayers__source__tilejson';
  $ol_source->options = array(
    'url' => 'http://api.tiles.mapbox.com/v3/financialtimes.map-w7l4lfi8.jsonp',
  );
  $export['source_mapbox_example3'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_geojson_cities';
  $ol_source->name = 'Cities GeoJSON';
  $ol_source->description = '';
  $ol_source->class = 'openlayers__source__geojson';
  $ol_source->options = array(
    'url' => file_create_url(drupal_get_path('module', 'openlayers_examples') . '/assets/cities.json'),
  );
  $export['source_geojson_cities'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_kml_earthquakes';
  $ol_source->name = '2012 Earthquakes';
  $ol_source->description = '';
  $ol_source->class = 'openlayers__source__kml';
  $ol_source->options = array(
    'url' => url(drupal_get_path('module', 'openlayers_examples') . '/assets/2012_Earthquakes_Mag5.kml', array('absolute' => TRUE)),
  );
  $export['source_kml_earthquakes'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_cluster_cities';
  $ol_source->name = 'Cluster cities';
  $ol_source->description = '';
  $ol_source->class = 'openlayers__source__cluster';
  $ol_source->options = array(
    'source' => 'source_geojson_cities',
    'distance' => '50',
  );
  $export['source_cluster_cities'] = $ol_source;

  return $export;
}
