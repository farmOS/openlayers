<?php
/**
 * @file
 * Default maps.
 */

/**
 * Implements hook_default_maps().
 */
function openlayers_examples_default_maps() {
  $export = array();

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_earthquake';
  $ol_map->name = '2012 Earthquakes map, tooltips and popups.';
  $ol_map->description = '';
  $ol_map->class = 'openlayers__map__map';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'view' => array(
      'center' => array(
        'lat' => 0,
        'lon' => 0,
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'layer_tile_stamen_toner',
      1 => 'layer_vector_kml_earthquakes_heatmap',
    ),
    'controls' => array(
      0 => 'control_zoom',
    ),
    'interactions' => array(
      0 => 'interaction_doubleclickzoom',
      1 => 'interaction_dragpan',
      2 => 'interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_earthquake_style',
      1 => 'openlayers_examples_simple_popup_earthquakes',
      2 => 'openlayers_examples_tooltip_earthquakes',
    ),
  );
  $export['openlayers_examples_map_earthquake'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'map_openstreetmap_geofield';
  $ol_map->name = 'OpenStreetMap with features';
  $ol_map->description = '';
  $ol_map->class = 'openlayers__map__map';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'layer_tile_openstreetmap',
    ),
    'controls' => array(),
    'interactions' => array(
      0 => 'interaction_doubleclickzoom',
      1 => 'interaction_dragpan',
      2 => 'interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_geofield',
    ),
  );
  $export['map_openstreetmap_geofield'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'map_mapbox_example1';
  $ol_map->name = 'Mapbox example 1';
  $ol_map->description = '';
  $ol_map->class = 'openlayers__map__map';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'layer_tile_mapbox_example1',
    ),
    'controls' => array(),
    'interactions' => array(
      0 => 'interaction_doubleclickzoom',
      1 => 'interaction_dragpan',
      2 => 'interaction_mousewheelzoom',
    ),
  );
  $export['map_mapbox_example1'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'map_mapbox_example2';
  $ol_map->name = 'Mapbox example 2';
  $ol_map->description = '';
  $ol_map->class = 'openlayers__map__map';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'layer_tile_mapbox_example2',
    ),
    'controls' => array(),
    'interactions' => array(
      0 => 'interaction_doubleclickzoom',
      1 => 'interaction_dragpan',
      2 => 'interaction_mousewheelzoom',
    ),
  );
  $export['map_mapbox_example2'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'map_mapbox_example3';
  $ol_map->name = 'Mapbox example 3';
  $ol_map->description = '';
  $ol_map->class = 'openlayers__map__map';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'layer_tile_mapbox_example3',
    ),
    'controls' => array(),
    'interactions' => array(
      0 => 'interaction_doubleclickzoom',
      1 => 'interaction_dragpan',
      2 => 'interaction_mousewheelzoom',
    ),
  );
  $export['map_mapbox_example3'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'map_geojson_cities';
  $ol_map->name = 'Map GeoJSON Cities';
  $ol_map->description = '';
  $ol_map->class = 'openlayers__map__map';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'layer_tile_mapbox_example3',
      1 => 'layer_vector_geojson_cities',
    ),
    'controls' => array(),
    'interactions' => array(
      0 => 'interaction_doubleclickzoom',
      1 => 'interaction_dragpan',
      2 => 'interaction_mousewheelzoom',
    ),
  );
  $export['map_geojson_cities'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'map_geojson_cities_heatmap';
  $ol_map->name = 'Map GeoJSON Cities Heatmap';
  $ol_map->description = '';
  $ol_map->class = 'openlayers__map__map';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'layer_tile_mapbox_example3',
      1 => 'layer_vector_geojson_cities_heatmap',
    ),
    'controls' => array(),
    'interactions' => array(
      0 => 'interaction_doubleclickzoom',
      1 => 'interaction_dragpan',
      2 => 'interaction_mousewheelzoom',
    ),
  );
  $export['map_geojson_cities_heatmap'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'map_geolocation';
  $ol_map->name = 'Map geolocation';
  $ol_map->description = '';
  $ol_map->class = 'openlayers__map__map';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'layer_tile_openstreetmap',
    ),
    'controls' => array(),
    'interactions' => array(
      0 => 'interaction_doubleclickzoom',
      1 => 'interaction_dragpan',
      2 => 'interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_geolocation',
    ),
  );
  $export['map_geolocation'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_mapquest_sat_geojson_views';
  $ol_map->name = 'MapQuest Satellite with features from Views GeoJSON';
  $ol_map->description = '';
  $ol_map->class = 'openlayers__map__map';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'layer_tile_mapquest_sat',
      1 => 'openlayers_examples_views_geojson',
    ),
    'controls' => array(
      0 => 'control_zoom',
      1 => 'control_zoomslider',
    ),
    'interactions' => array(),
    'components' => array(
      0 => 'openlayers_examples_zoom_to_source',
    ),
  );
  $export['openlayers_examples_mapquest_sat_geojson_views'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_cluster';
  $ol_map->name = 'Map with cluster';
  $ol_map->description = '';
  $ol_map->class = 'openlayers__map__map';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
      'minZoom' => '0',
      'maxZoom' => '0',
    ),
    'layers' => array(
      0 => 'layer_tile_mapquest_osm',
      1 => 'layer_cluster_cities',
    ),
    'sources' => array(
      0 => 'source_mapquest_osm',
      1 => 'source_geojson_cities',
      2 => 'source_cluster_cities',
    ),
    'controls' => array(
      0 => 'control_zoom',
      1 => 'control_zoomslider',
    ),
    'interactions' => array(
      0 => 'interaction_doubleclickzoom',
      1 => 'interaction_dragpan',
    ),
    'components' => array(),
  );
  $export['openlayers_examples_cluster'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_popup_overlay';
  $ol_map->name = 'Map with simple popup overlay and autozoom.';
  $ol_map->description = '';
  $ol_map->class = 'openlayers__map__map';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
      'minZoom' => '0',
      'maxZoom' => '0',
    ),
    'layers' => array(
      0 => 'layer_tile_mapquest_osm',
      1 => 'openlayers_examples_views_geojson_popup',
    ),
    'sources' => array(
      0 => 'source_mapquest_osm',
    ),
    'controls' => array(
      0 => 'control_attribution',
      1 => 'control_scaleline',
      2 => 'control_zoom',
    ),
    'interactions' => array(
      0 => 'interaction_doubleclickzoom',
      1 => 'interaction_dragpan',
      2 => 'interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_simple_popup',
      1 => 'openlayers_examples_zoom_to_source',
    ),
  );
  $export['openlayers_examples_map_popup_overlay'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_blocklayerswitcher';
  $ol_map->name = 'Map with block layer switcher';
  $ol_map->description = '';
  $ol_map->class = 'openlayers__map__map';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'layer_tile_mapbox_geography_class',
      1 => 'layer_tile_mapquest_hyb',
      2 => 'layer_tile_mapquest_sat',
      3 => 'layer_tile_stamen_toner',
      4 => 'layer_tile_mapquest_osm',
      5 => 'layer_tile_openstreetmap',
      6 => 'layer_vector_kml_earthquakes',
      7 => 'openlayers_examples_views_geojson',
      8 => 'layer_vector_geojson_cities_heatmap',
      9 => 'layer_vector_kml_earthquakes_heatmap',
      10 => 'layer_vector_geojson_cities',
      11 => 'layer_cluster_cities',
    ),
    'controls' => array(
      0 => 'control_zoom',
    ),
    'interactions' => array(
      0 => 'interaction_doubleclickzoom',
      1 => 'interaction_dragpan',
      2 => 'interaction_mousewheelzoom',
    ),
    'sources' => array(
      0 => 'source_osm',
      1 => 'source_mapbox_geography_class',
      2 => 'source_mapquest_hyb',
      3 => 'source_mapquest_sat',
      4 => 'source_stamen3',
      5 => 'source_mapquest_osm',
      6 => 'source_kml_earthquakes',
      7 => 'views_geojson_openlayers_examples_geojson_feed_1',
      8 => 'source_geojson_cities',
      9 => 'source_cluster_cities',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_blocklayerswitcher',
    ),
  );
  $export['openlayers_examples_blocklayerswitcher'] = $ol_map;

  return $export;
}
