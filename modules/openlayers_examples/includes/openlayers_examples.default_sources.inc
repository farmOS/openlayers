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
  $ol_source->machine_name = 'openlayers_examples_source_mapbox_example1';
  $ol_source->name = 'MapBox example 1';
  $ol_source->description = 'Source MapBox example 1';
  $ol_source->factory_service = 'openlayers.source.internal.TileJSON';
  $ol_source->options = array(
    'url' => 'http://api.tiles.mapbox.com/v3/examples.map-i86nkdio.jsonp',
  );
  $export['openlayers_examples_source_mapbox_example1'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_googlemaps';
  $ol_source->name = 'Google Maps';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.source.internal.GoogleMaps';
  $ol_source->options = array(
    'key' => '',
    'client' => '',
    'channel' => '',
    'mapTypeId' => 'ROADMAP',
    'sensor' => 0,
  );
  $export['openlayers_examples_source_googlemaps'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_europa';
  $ol_source->name = 'EC Europa Webtools';
  $ol_source->description = 'Source from European Commission webtools based on OSM, with some modifications.';
  $ol_source->factory_service = 'openlayers.source.internal.XYZ';
  $ol_source->options = array(
    'url' => 'http://webtools.ec.europa.eu/road-maps/tiles/{z}/{x}/{y}.png',
  );
  $export['openlayers_examples_source_europa'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_mapbox_example2';
  $ol_source->name = 'MapBox example 2';
  $ol_source->description = 'Source MapBox example 2';
  $ol_source->factory_service = 'openlayers.source.internal.TileJSON';
  $ol_source->options = array(
    'url' => 'http://api.tiles.mapbox.com/v3/examples.c7d2024a.jsonp',
  );
  $export['openlayers_examples_source_mapbox_example2'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_mapbox_example3';
  $ol_source->name = 'MapBox example 3';
  $ol_source->description = 'Source MapBox example 3, used by ft.com.';
  $ol_source->factory_service = 'openlayers.source.internal.TileJSON';
  $ol_source->options = array(
    'url' => 'http://api.tiles.mapbox.com/v3/financialtimes.map-w7l4lfi8.jsonp',
  );
  $export['openlayers_examples_source_mapbox_example3'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_geojson_file';
  $ol_source->name = 'Cities GeoJSON';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.source.internal.GeoJSON';
  $ol_source->options = array(
    'url' => file_create_url(drupal_get_path('module', 'openlayers_examples') . '/assets/cities.json'),
  );
  $export['openlayers_examples_source_geojson_file'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_kml_earthquakes';
  $ol_source->name = '2012 Earthquakes';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.source.internal.KML';
  $ol_source->options = array(
    'url' => url(drupal_get_path('module', 'openlayers_examples') . '/assets/2012_Earthquakes_Mag5.kml', array('absolute' => TRUE)),
  );
  $export['openlayers_examples_source_kml_earthquakes'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_cluster';
  $ol_source->name = 'Cluster cities';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.source.internal.Cluster';
  $ol_source->options = array(
    'source' => 'openlayers_examples_source_geojson_file',
    'distance' => '50',
  );
  $export['openlayers_examples_source_cluster'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openstreetmap';
  $ol_source->name = 'OpenStreetMap';
  $ol_source->description = 'Source OpenStreetMap description';
  $ol_source->factory_service = 'openlayers.source.internal.OSM';
  $ol_source->options = array();
  $export['openlayers_examples_source_openstreetmap'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_opencyclemap';
  $ol_source->name = 'OpenCycleMap';
  $ol_source->description = 'Source OpenCycleMap description';
  $ol_source->factory_service = 'openlayers.source.internal.OSM';
  $ol_source->options = array(
    'url' => 'http://{a-c}.tile.opencyclemap.org/cycle/{z}/{x}/{y}.png',
  );
  $export['openlayers_examples_source_opencyclemap'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_bingmaps';
  $ol_source->name = 'Bing Maps';
  $ol_source->description = 'Source Bingmaps description';
  $ol_source->factory_service = 'openlayers.source.internal.BingMaps';
  $ol_source->options = array();
  $export['openlayers_examples_source_bingmaps'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_mapquest_sat';
  $ol_source->name = 'MapQuest Satellite';
  $ol_source->description = 'Source MapQuest Satellite description';
  $ol_source->factory_service = 'openlayers.source.internal.MapQuest';
  $ol_source->options = array(
    'layer' => 'sat',
  );
  $export['openlayers_examples_source_mapquest_sat'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_mapquest_hyb';
  $ol_source->name = 'MapQuest Hybrid';
  $ol_source->description = 'Source MapQuest Hybrid';
  $ol_source->factory_service = 'openlayers.source.internal.MapQuest';
  $ol_source->options = array(
    'layer' => 'hyb',
  );
  $export['openlayers_examples_source_mapquest_hyb'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_mapbox_geography_class';
  $ol_source->name = 'MapBox Geography Class';
  $ol_source->description = 'Source MapBox Geography Class description';
  $ol_source->factory_service = 'openlayers.source.internal.TileJSON';
  $ol_source->options = array(
    'url' => 'http://api.tiles.mapbox.com/v3/mapbox.geography-class.jsonp',
  );
  $export['openlayers_examples_source_mapbox_geography_class'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_mapbox_natural_earth_hypso_bathy';
  $ol_source->name = 'MapBox Natural Earth Hypso Bathy';
  $ol_source->description = 'Source MapBox Natural Hearth Hypso Bathy description';
  $ol_source->factory_service = 'openlayers.source.internal.TileJSON';
  $ol_source->options = array(
    'url' => 'http://api.tiles.mapbox.com/v3/mapbox.natural-earth-hypso-bathy.jsonp',
  );
  $export['openlayers_examples_source_mapbox_natural_earth_hypso_bathy'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_imagestatic';
  $ol_source->name = 'Image Static';
  $ol_source->description = 'Source Image Static description';
  $ol_source->factory_service = 'openlayers.source.internal.ImageStatic';
  $ol_source->options = array(
    'url' => url(drupal_get_path('module', 'openlayers') . '/images/druplicon.png', array('absolute' => TRUE)),
  );
  $export['openlayers_examples_source_imagestatic'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_tiledebug';
  $ol_source->name = 'Tile debug';
  $ol_source->description = 'A pseudo tile source, which does not fetch tiles from a server, but renders a grid outline for the tile grid/projection along with the coordinates for each tile.';
  $ol_source->factory_service = 'openlayers.source.internal.TileDebug';
  $ol_source->options = array(
    'maxZoom' => 22,
  );
  $export['openlayers_examples_source_tiledebug'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_stamen1';
  $ol_source->name = 'Stamen terrain labels';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.source.internal.Stamen';
  $ol_source->options = array(
    'layer' => 'terrain-labels',
  );
  $export['openlayers_examples_source_stamen1'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_stamen2';
  $ol_source->name = 'Stamen watercolor';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.source.internal.Stamen';
  $ol_source->options = array(
    'layer' => 'watercolor',
  );
  $export['openlayers_examples_source_stamen2'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_stamen3';
  $ol_source->name = 'Stamen toner';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.source.internal.Stamen';
  $ol_source->options = array(
    'layer' => 'toner',
  );
  $export['openlayers_examples_source_stamen3'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_esri';
  $ol_source->name = 'ESRI';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.source.internal.XYZ';
  $ol_source->options = array(
    'url' => 'http://server.arcgisonline.com/ArcGIS/rest/services/World_Topo_Map/MapServer/tile/{z}/{y}/{x}',
  );
  $export['openlayers_examples_source_esri'] = $ol_source;

  return $export;
}
