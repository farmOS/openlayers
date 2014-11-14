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
  $ol_layer->class = 'openlayers__layer__tile';
  $ol_layer->options = array(
    'source' => 'source_mapbox_example1',
  );
  $export['layer_tile_mapbox_example1'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_mapbox_example2';
  $ol_layer->name = 'MapBox example 2';
  $ol_layer->description = 'Layer MapBox example 2';
  $ol_layer->class = 'openlayers__layer__tile';
  $ol_layer->options = array(
    'source' => 'source_mapbox_example2',
  );
  $export['layer_tile_mapbox_example2'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_mapbox_example3';
  $ol_layer->name = 'MapBox example 2';
  $ol_layer->description = 'Layer MapBox example 3';
  $ol_layer->class = 'openlayers__layer__tile';
  $ol_layer->options = array(
    'source' => 'source_mapbox_example3',
  );
  $export['layer_tile_mapbox_example3'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_vector_geojson_cities';
  $ol_layer->name = 'GeoJSON Cities';
  $ol_layer->description = 'GeoJSON Cities';
  $ol_layer->class = 'openlayers__layer__vector';
  $ol_layer->options = array(
    'source' => 'source_geojson_cities',
  );
  $export['layer_vector_geojson_cities'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_vector_geojson_cities_heatmap';
  $ol_layer->name = 'GeoJSON Cities heatmap';
  $ol_layer->description = 'GeoJSON Cities Heatmap';
  $ol_layer->class = 'openlayers__layer__heatmap';
  $ol_layer->options = array(
    'source' => 'source_geojson_cities',
  );
  $export['layer_vector_geojson_cities_heatmap'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_vector_kml_earthquakes';
  $ol_layer->name = 'Earthquakes 2012';
  $ol_layer->description = '';
  $ol_layer->class = 'openlayers__layer__vector';
  $ol_layer->options = array(
    'source' => 'source_kml_earthquakes',
  );
  $export['layer_vector_kml_earthquakes'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_vector_kml_earthquakes_heatmap';
  $ol_layer->name = 'Earthquakes 2012 Heatmap';
  $ol_layer->description = '';
  $ol_layer->class = 'openlayers__layer__heatmap';
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
  $ol_layer->class = 'openlayers__layer__vector';
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
  $ol_layer->class = 'openlayers__layer__vector';
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
  $ol_layer->class = 'openlayers__layer__vector';
  $ol_layer->options = array(
    'source' => 'views_geojson_openlayers_examples_geojson_feed_2',
    'style' => 'openlayers_examples_blue_marker',
  );
  $export['openlayers_examples_views_geojson_popup'] = $ol_layer;

  return $export;
}
