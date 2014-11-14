<?php
/**
 * @file
 * Provide default sources.
 */

/**
 * Implements hook_default_sources().
 */
function openlayers_default_sources() {
  $export = array();

  $ol_source = new stdClass();
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_osm';
  $ol_source->name = 'OpenStreetMap';
  $ol_source->description = 'Source OpenStreetMap description';
  $ol_source->class = 'openlayers__source__osm';
  $ol_source->options = array();
  $export['source_osm'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_osm_opencyclemap';
  $ol_source->name = 'OpenCycleMap';
  $ol_source->description = 'Source OpenCycleMap description';
  $ol_source->class = 'openlayers__source__osm';
  $ol_source->options = array(
    'url' => 'http://{a-c}.tile.opencyclemap.org/cycle/{z}/{x}/{y}.png',
  );
  $export['source_osm_opencyclemap'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_bingmaps';
  $ol_source->name = 'Bing Maps';
  $ol_source->description = 'Source Bingmaps description';
  $ol_source->class = 'openlayers__source__bingmaps';
  $ol_source->options = array();
  $export['source_bingmaps'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_googlemaps';
  $ol_source->name = 'Google Maps';
  $ol_source->description = 'Source Google description';
  $ol_source->class = 'openlayers__source__googlemaps';
  $ol_source->options = array();
  $export['source_googlemaps'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_mapquest_sat';
  $ol_source->name = 'MapQuest Satellite';
  $ol_source->description = 'Source MapQuest Satellite description';
  $ol_source->class = 'openlayers__source__mapquest';
  $ol_source->options = array(
    'layer' => 'sat',
  );
  $export['source_mapquest_sat'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_mapquest_osm';
  $ol_source->name = 'MapQuest OpenStreetMap';
  $ol_source->description = 'Source MapQuest OpenStreetMap description';
  $ol_source->class = 'openlayers__source__mapquest';
  $ol_source->options = array(
    'layer' => 'osm',
  );
  $export['source_mapquest_osm'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_mapquest_hyb';
  $ol_source->name = 'MapQuest Hybrid';
  $ol_source->description = 'Source MapQuest Hybrid';
  $ol_source->class = 'openlayers__source__mapquest';
  $ol_source->options = array(
    'layer' => 'hyb',
  );
  $export['source_mapquest_hyb'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_mapbox_geography_class';
  $ol_source->name = 'MapBox Geography Class';
  $ol_source->description = 'Source MapBox Geography Class description';
  $ol_source->class = 'openlayers__source__tilejson';
  $ol_source->options = array(
    'url' => 'http://api.tiles.mapbox.com/v3/mapbox.geography-class.jsonp',
  );
  $export['source_mapbox_geography_class'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_mapbox_natural_earth_hypso_bathy';
  $ol_source->name = 'MapBox Natural Earth Hypso Bathy';
  $ol_source->description = 'Source MapBox Natural Hearth Hypso Bathy description';
  $ol_source->class = 'openlayers__source__tilejson';
  $ol_source->options = array(
    'url' => 'http://api.tiles.mapbox.com/v3/mapbox.natural-earth-hypso-bathy.jsonp',
  );
  $export['source_mapbox_natural_earth_hypso_bathy'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_imagestatic';
  $ol_source->name = 'Image Static';
  $ol_source->description = 'Source Image Static description';
  $ol_source->class = 'openlayers__source__imagestatic';
  $ol_source->options = array(
    'url' => url(drupal_get_path('module', 'openlayers') . '/images/druplicon.png', array('absolute' => TRUE)),
  );
  $export['source_imagestatic'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_tiledebug';
  $ol_source->name = 'Tile debug';
  $ol_source->description = 'A pseudo tile source, which does not fetch tiles from a server, but renders a grid outline for the tile grid/projection along with the coordinates for each tile.';
  $ol_source->class = 'openlayers__source__tiledebug';
  $ol_source->options = array(
    'maxZoom' => 22,
  );
  $export['source_tiledebug'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_stamen1';
  $ol_source->name = 'Stamen terrain labels';
  $ol_source->description = '';
  $ol_source->class = 'openlayers__source__stamen';
  $ol_source->options = array(
    'layer' => 'terrain-labels',
  );
  $export['source_stamen1'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_stamen2';
  $ol_source->name = 'Stamen watercolor';
  $ol_source->description = '';
  $ol_source->class = 'openlayers__source__stamen';
  $ol_source->options = array(
    'layer' => 'watercolor',
  );
  $export['source_stamen2'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_stamen3';
  $ol_source->name = 'Stamen toner';
  $ol_source->description = '';
  $ol_source->class = 'openlayers__source__stamen';
  $ol_source->options = array(
    'layer' => 'toner',
  );
  $export['source_stamen3'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_esri';
  $ol_source->name = 'ESRI';
  $ol_source->description = '';
  $ol_source->class = 'openlayers__source__xyz';
  $ol_source->options = array(
    'url' => 'http://server.arcgisonline.com/ArcGIS/rest/services/World_Topo_Map/MapServer/tile/{z}/{y}/{x}',
  );
  $export['source_esri'] = $ol_source;

  return $export;
}

/**
 * On behalf of views_geojson.
 */
function views_geojson_default_sources() {
  $export = array();
  foreach (views_get_all_views() as $view) {
    foreach ($view->display as $display => $data) {
      $view->set_display($display);
      if (in_array($view->display_handler->get_option('style_plugin'), array('views_geojson_feed', 'views_geojson'))) {
        $ol_source = new stdClass();
        $ol_source->api_version = 1;
        $ol_source->machine_name = 'views_geojson_' . $view->name . '_' . $display;
        $ol_source->name = 'Views GeoJSON source: ' . $view->name . '_' . $display;
        $ol_source->description = 'This source is automatically generated. See View ' . $view->name . ' at display ' . $display;
        $ol_source->class = 'openlayers__source__geojson';

        $ol_source->options = array(
          'url' => url($view->display_handler->get_url(), array('absolute' => TRUE)),
        );

        // Determine if we should use a BBox strategy.
        if ($arguments = $view->display_handler->get_option('arguments')) {
          foreach ($arguments as $id => $argument) {
            if (strpos($id, 'bbox') !== FALSE && $argument['default_argument_type'] == 'querystring') {
              if (isset($argument['default_argument_options'])) {
                $ol_source->options['useBBOX'] = TRUE;
              }
            }
          }
        }
        $export[$ol_source->machine_name] = $ol_source;
      }
    }
  }

  return $export;
}
