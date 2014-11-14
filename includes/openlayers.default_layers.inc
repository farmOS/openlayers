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
  $ol_layer->class = 'openlayers__layer__tile';
  $ol_layer->options = array(
    'source' => 'source_mapquest_osm',
  );
  $export['layer_tile_mapquest_osm'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_mapquest_sat';
  $ol_layer->name = 'MapQuest Satellite';
  $ol_layer->description = 'Layer MapQuest Satellite description';
  $ol_layer->class = 'openlayers__layer__tile';
  $ol_layer->options = array(
    'source' => 'source_mapquest_sat',
  );
  $export['layer_tile_mapquest_sat'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_mapquest_hyb';
  $ol_layer->name = 'MapQuest Hybrid';
  $ol_layer->description = 'Layer MapQuest Hybrid description';
  $ol_layer->class = 'openlayers__layer__tile';
  $ol_layer->options = array(
    'source' => 'source_mapquest_hyb',
  );
  $export['layer_tile_mapquest_hyb'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_mapbox_geography_class';
  $ol_layer->name = 'MapBox Geography Class';
  $ol_layer->description = 'Layer MapBox Geography Class description';
  $ol_layer->class = 'openlayers__layer__tile';
  $ol_layer->options = array(
    'source' => 'source_mapbox_geography_class',
  );
  $export['layer_tile_mapbox_geography_class'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_tile_mapbox_natural_earth_hypso_bathy';
  $ol_layer->name = 'MapBox Natural Earth Hypso Bathy';
  $ol_layer->description = 'Layer MapBox Natural Earth Hypso Bathy description';
  $ol_layer->class = 'openlayers__layer__tile';
  $ol_layer->options = array(
    'source' => 'source_mapbox_natural_earth_hypso_bathy',
  );
  $export['layer_tile_mapbox_natural_earth_hypso_bathy'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_image';
  $ol_layer->name = 'Drupal logo layer image';
  $ol_layer->description = 'Layer image description';
  $ol_layer->class = 'openlayers__layer__image';
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
  $ol_layer->class = 'openlayers__layer__tile';
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
  $ol_layer->class = 'openlayers__layer__tile';
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
  $ol_layer->class = 'openlayers__layer__tile';
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
  $ol_layer->class = 'openlayers__layer__tile';
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
  $ol_layer->class = 'openlayers__layer__tile';
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
  $ol_layer->class = 'openlayers__layer__tile';
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
  $ol_layer->class = 'openlayers__layer__tile';
  $ol_layer->options = array(
    'source' => 'source_esri',
  );
  $export['layer_tile_esri'] = $ol_layer;

  return $export;
}
