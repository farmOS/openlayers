<?php
/**
 * @file
 * Default layers.
 */

/**
 * Implements hook_default_layers().
 */
function openlayers_examples_default_layers() {
  $export = array();

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_mapbox_example1';
  $ol_layer->name = 'MapBox example 1';
  $ol_layer->description = 'Layer MapBox example 1';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\tile';
  $ol_layer->options = array(
    'source' => 'source_mapbox_example1',
  );
  $export['layer_tile_mapbox_example1'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_mapbox_example2';
  $ol_layer->name = 'MapBox example 2';
  $ol_layer->description = 'Layer MapBox example 2';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\tile';
  $ol_layer->options = array(
    'source' => 'source_mapbox_example2',
  );
  $export['layer_tile_mapbox_example2'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_mapbox_example3';
  $ol_layer->name = 'MapBox example 2';
  $ol_layer->description = 'Layer MapBox example 3';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\tile';
  $ol_layer->options = array(
    'source' => 'source_mapbox_example3',
  );
  $export['layer_tile_mapbox_example3'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_vector_geojson_cities';
  $ol_layer->name = 'GeoJSON Cities';
  $ol_layer->description = 'GeoJSON Cities';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\vector';
  $ol_layer->options = array(
    'source' => 'source_geojson_cities',
  );
  $export['layer_vector_geojson_cities'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_vector_geojson_cities_heatmap';
  $ol_layer->name = 'GeoJSON Cities heatmap';
  $ol_layer->description = 'GeoJSON Cities Heatmap';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\heatmap';
  $ol_layer->options = array(
    'source' => 'source_geojson_cities',
  );
  $export['layer_vector_geojson_cities_heatmap'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_vector_kml_earthquakes';
  $ol_layer->name = 'Earthquakes 2012';
  $ol_layer->description = '';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\vector';
  $ol_layer->options = array(
    'source' => 'source_kml_earthquakes',
  );
  $export['layer_vector_kml_earthquakes'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_vector_kml_earthquakes_heatmap';
  $ol_layer->name = 'Earthquakes 2012 Heatmap';
  $ol_layer->description = '';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\heatmap';
  $ol_layer->options = array(
    'source' => 'source_kml_earthquakes',
  );
  $export['layer_vector_kml_earthquakes_heatmap'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_views_geojson';
  $ol_layer->name = 'Layer with source from Views GeoJSON';
  $ol_layer->description = '';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\vector';
  $ol_layer->options = array(
    'source' => 'views_geojson_openlayers_examples_geojson_feed_1',
  );
  $export['openlayers_examples_views_geojson'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_cluster_cities';
  $ol_layer->name = 'Layer cluster cities';
  $ol_layer->description = '';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\vector';
  $ol_layer->options = array(
    'source' => 'source_cluster_cities',
  );
  $export['layer_cluster_cities'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_views_geojson_popup';
  $ol_layer->name = 'Layer with source from Views GeoJSON for popup';
  $ol_layer->description = '';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\vector';
  $ol_layer->options = array(
    'source' => 'views_geojson_openlayers_examples_geojson_feed_2',
    'style' => 'openlayers_examples_blue_marker',
  );
  $export['openlayers_examples_views_geojson_popup'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_mapquest_sat';
  $ol_layer->name = 'MapQuest Satellite';
  $ol_layer->description = 'Layer MapQuest Satellite description';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\tile';
  $ol_layer->options = array(
    'source' => 'source_mapquest_sat',
  );
  $export['layer_tile_mapquest_sat'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_mapquest_hyb';
  $ol_layer->name = 'MapQuest Hybrid';
  $ol_layer->description = 'Layer MapQuest Hybrid description';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\tile';
  $ol_layer->options = array(
    'source' => 'source_mapquest_hyb',
  );
  $export['layer_tile_mapquest_hyb'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_mapbox_geography_class';
  $ol_layer->name = 'MapBox Geography Class';
  $ol_layer->description = 'Layer MapBox Geography Class description';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\tile';
  $ol_layer->options = array(
    'source' => 'source_mapbox_geography_class',
  );
  $export['layer_tile_mapbox_geography_class'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_mapbox_natural_earth_hypso_bathy';
  $ol_layer->name = 'MapBox Natural Earth Hypso Bathy';
  $ol_layer->description = 'Layer MapBox Natural Earth Hypso Bathy description';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\tile';
  $ol_layer->options = array(
    'source' => 'source_mapbox_natural_earth_hypso_bathy',
  );
  $export['layer_tile_mapbox_natural_earth_hypso_bathy'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_image';
  $ol_layer->name = 'Drupal logo layer image';
  $ol_layer->description = 'Layer image description';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\image';
  $ol_layer->options = array(
    'source' => 'source_imagestatic',
  );
  $export['layer_image'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_openstreetmap';
  $ol_layer->name = 'OpenStreetMap';
  $ol_layer->description = '';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\tile';
  $ol_layer->options = array(
    'source' => 'source_osm',
  );
  $export['layer_tile_openstreetmap'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_opencyclemap';
  $ol_layer->name = 'OpenCycleMap';
  $ol_layer->description = '';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\tile';
  $ol_layer->options = array(
    'source' => 'source_osm_opencyclemap',
  );
  $export['layer_tile_opencyclemap'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_tiledebug';
  $ol_layer->name = 'Tile Debug';
  $ol_layer->description = '';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\tile';
  $ol_layer->options = array(
    'source' => 'source_tiledebug',
  );
  $export['layer_tile_tiledebug'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_stamen_terrain_labels';
  $ol_layer->name = 'Stamen terrain labels';
  $ol_layer->description = '';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\tile';
  $ol_layer->options = array(
    'source' => 'source_stamen1',
  );
  $export['layer_tile_stamen_terrain_labels'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_stamen_watercolor';
  $ol_layer->name = 'Stamen watercolor';
  $ol_layer->description = '';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\tile';
  $ol_layer->options = array(
    'source' => 'source_stamen2',
  );
  $export['layer_tile_stamen_watercolor'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_stamen_toner';
  $ol_layer->name = 'Stamen toner';
  $ol_layer->description = '';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\tile';
  $ol_layer->options = array(
    'source' => 'source_stamen3',
  );
  $export['layer_tile_stamen_toner'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_esri';
  $ol_layer->name = 'ESRI';
  $ol_layer->description = '';
  $ol_layer->class = '\\Drupal\\openlayers\\Layer\\tile';
  $ol_layer->options = array(
    'source' => 'source_esri',
  );
  $export['layer_tile_esri'] = $ol_layer;

  return $export;
}
