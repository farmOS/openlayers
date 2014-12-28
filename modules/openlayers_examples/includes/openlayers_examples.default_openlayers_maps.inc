<?php
/**
 * @file
 * Default maps.
 */

/**
 * Implements hook_default_maps().
 */
function openlayers_examples_default_openlayers_maps() {
  $export = array();

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_earthquake';
  $ol_map->name = '2012 Earthquakes map, tooltips and popups.';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => 0,
        'lon' => 0,
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_stamen3',
      1 => 'openlayers_examples_layer_vector_kml_earthquakes_heatmap',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_earthquake_style',
      1 => 'openlayers_examples_component_simple_popup_earthquakes',
      2 => 'openlayers_examples_component_tooltip_earthquakes',
    ),
  );
  $export['openlayers_examples_map_earthquake'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_geofield';
  $ol_map->name = 'Map with features input';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_openstreetmap',
    ),
    'controls' => array(),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_geofield',
    ),
  );
  $export['openlayers_examples_map_geofield'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_mapbox_example1';
  $ol_map->name = 'Mapbox example 1';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_tile_mapbox_example1',
    ),
    'controls' => array(),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_mapbox_example1'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_mapbox_example2';
  $ol_map->name = 'Mapbox example 2';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_tile_mapbox_example2',
    ),
    'controls' => array(),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_mapbox_example2'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_mapbox_example3';
  $ol_map->name = 'Mapbox example 3';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_tile_mapbox_example3',
    ),
    'controls' => array(),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_mapbox_example3'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_geojson_cities';
  $ol_map->name = 'Map GeoJSON Cities';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_tile_mapbox_example3',
      1 => 'openlayers_examples_layer_vector_geojson_cities',
    ),
    'controls' => array(),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_geojson_cities'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_geojson_cities_heatmap';
  $ol_map->name = 'Map GeoJSON Cities Heatmap';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_tile_mapbox_example3',
      1 => 'openlayers_examples_layer_vector_geojson_cities_heatmap',
    ),
    'controls' => array(),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_geojson_cities_heatmap'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_geolocation';
  $ol_map->name = 'Map geolocation';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_openstreetmap',
    ),
    'controls' => array(),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_geolocation',
    ),
  );
  $export['openlayers_examples_map_geolocation'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_mapquest_views_geojson';
  $ol_map->name = 'MapQuest Satellite with features from Views GeoJSON';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_mapquest_sat',
      1 => 'openlayers_examples_layer_views_geojson',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
      1 => 'openlayers_control_zoomslider',
    ),
    'interactions' => array(),
    'components' => array(
      0 => 'openlayers_examples_component_zoom_to_source',
    ),
  );
  $export['openlayers_examples_map_mapquest_views_geojson'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_geojson_cluster';
  $ol_map->name = 'Map with cluster';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
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
      0 => 'openlayers_layer_tile_mapquest_osm',
      1 => 'openlayers_examples_layer_cluster_cities',
    ),
    'sources' => array(
      0 => 'openlayers_source_mapquest_osm',
      1 => 'openlayers_examples_source_geojson_file',
      2 => 'openlayers_examples_source_cluster',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
      1 => 'openlayers_control_zoomslider',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
    ),
    'components' => array(),
  );
  $export['openlayers_examples_map_geojson_cluster'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_popup_autozoom';
  $ol_map->name = 'Map with simple popup overlay and autozoom.';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
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
      0 => 'openlayers_layer_tile_mapquest_osm',
      1 => 'openlayers_examples_layer_views_geojson_popup',
    ),
    'sources' => array(
      0 => 'openlayers_source_mapquest_osm',
    ),
    'controls' => array(
      0 => 'openlayers_control_attribution',
      1 => 'openlayers_control_scaleline',
      2 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_simple_popup',
      1 => 'openlayers_examples_component_zoom_to_source',
    ),
  );
  $export['openlayers_examples_map_popup_autozoom'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_blocklayerswitcher';
  $ol_map->name = 'Map with block layer switcher';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_mapbox_geography_class',
      1 => 'openlayers_examples_layer_mapquest_hyb',
      2 => 'openlayers_examples_layer_mapquest_sat',
      3 => 'openlayers_examples_layer_stamen3',
      4 => 'openlayers_layer_tile_mapquest_osm',
      5 => 'openlayers_examples_layer_openstreetmap',
      6 => 'openlayers_examples_layer_vector_kml_earthquakes',
      7 => 'openlayers_examples_layer_views_geojson',
      8 => 'openlayers_examples_layer_vector_geojson_cities_heatmap',
      9 => 'openlayers_examples_layer_vector_kml_earthquakes_heatmap',
      10 => 'openlayers_examples_layer_vector_geojson_cities',
      11 => 'openlayers_examples_layer_cluster_cities',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
    'sources' => array(
      0 => 'openlayers_examples_source_openstreetmap',
      1 => 'openlayers_examples_source_mapbox_geography_class',
      2 => 'openlayers_examples_source_mapquest_hyb',
      3 => 'openlayers_examples_source_mapquest_sat',
      4 => 'openlayers_examples_source_stamen3',
      5 => 'openlayers_source_mapquest_osm',
      6 => 'openlayers_examples_source_kml_earthquakes',
      7 => 'views_geojson_openlayers_examples_geojson_feed_1',
      8 => 'openlayers_examples_source_geojson_file',
      9 => 'openlayers_examples_source_cluster',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_blocklayerswitcher',
    ),
  );
  $export['openlayers_examples_map_blocklayerswitcher'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_mapbox_natural_earth_hypso_bathy';
  $ol_map->name = 'MapBox Natural Earth Hypso Bathy';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_mapbox_natural_earth_hypso_bathy',
    ),
    'controls' => array(
      0 => 'openlayers_control_rotate',
      1 => 'openlayers_control_scaleline',
      2 => 'openlayers_control_zoom',
      3 => 'openlayers_control_zoomslider',
      4 => 'openlayers_control_zoomtoextent',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotate',
      3 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_mapbox_natural_earth_hypso_bathy'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_mapbox_geography_class';
  $ol_map->name = 'MapBox Geography Class';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_mapbox_geography_class',
      1 => 'openlayers_examples_layer_mapbox_geography_class_utfgrid',
    ),
    'controls' => array(
      0 => 'openlayers_control_rotate',
      1 => 'openlayers_control_scaleline',
      2 => 'openlayers_control_zoom',
      3 => 'openlayers_control_zoomslider',
      4 => 'openlayers_control_zoomtoextent',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotate',
      3 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_tileutfgrid'
    )
  );
  $export['openlayers_examples_map_mapbox_geography_class'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_mapquest_openstreetmap';
  $ol_map->name = 'MapQuest OpenStreetMap';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
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
      0 => 'openlayers_layer_tile_mapquest_osm',
    ),
    'controls' => array(
      0 => 'openlayers_control_rotate',
      1 => 'openlayers_control_scaleline',
      2 => 'openlayers_control_zoom',
      3 => 'openlayers_control_zoomslider',
      4 => 'openlayers_control_zoomtoextent',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotate',
      3 => 'openlayers_interaction_keyboardpan',
      4 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_mapquest_openstreetmap'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_mapquest_hybrid';
  $ol_map->name = 'MapQuest Hybrid';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_mapquest_sat',
      1 => 'openlayers_examples_layer_mapquest_hyb',
    ),
    'controls' => array(
      0 => 'openlayers_control_attribution',
      1 => 'openlayers_control_rotate',
      2 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotateandzoom',
      3 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_mapquest_hybrid'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_mapquest_satellite';
  $ol_map->name = 'MapQuest Satellite';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_mapquest_sat',
    ),
    'controls' => array(
      0 => 'openlayers_control_mouseposition',
      1 => 'openlayers_control_scaleline',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotateandzoom',
      3 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_mapquest_satellite'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_ec_europa_osm';
  $ol_map->name = 'EC Europa OpenStreetMap';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '400px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_openstreetmap',
      1 => 'openlayers_examples_layer_europa',
    ),
    'controls' => array(
      0 => 'openlayers_examples_control_simple_layer_switcher',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_ec_europa_osm'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_openstreetmap';
  $ol_map->name = 'OpenStreetMap';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_openstreetmap',
    ),
    'controls' => array(),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_openstreetmap'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_opencyclemap';
  $ol_map->name = 'OpenCycleMap';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
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
      0 => 'openlayers_examples_layer_opencyclemap',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
      1 => 'openlayers_control_zoomslider',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(),
  );
  $export['openlayers_examples_map_opencyclemap'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_openstreetmap_tiledebug';
  $ol_map->name = 'OpenStreetMap with tile debug.';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_openstreetmap',
      1 => 'openlayers_examples_layer_tiledebug',
    ),
    'controls' => array(),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_openstreetmap_tiledebug'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_stamen';
  $ol_map->name = 'Stamen map';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => 0,
        'lon' => 0,
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_stamen2',
      1 => 'openlayers_examples_layer_stamen1',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_stamen'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_esri';
  $ol_map->name = 'ESRI map';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => 0,
        'lon' => 0,
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_esri',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_esri'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_googlemaps';
  $ol_map->name = 'Google Maps';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '400px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideBlockLayerSwitcher' => 0,
    'provideIframe' => 1,
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
      0 => 'openlayers_examples_layer_googlemaps',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_googlemaps'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_atlas_webgl';
  $ol_map->name = 'OpenLayers Examples Map Atlas WebGL';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'renderer' => 'webgl',
    'width' => 'auto',
    'height' => '300px',
    'provideBlock' => 0,
    'provideBlockLayerSwitcher' => 0,
    'contextualLinks' => 0,
    'provideIframe' => 0,
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
      0 => 'openlayers_examples_layer_atlas_webgl',
    ),
    'sources' => array(),
    'controls' => array(
      0 => 'openlayers_control_fullscreen',
      1 => 'openlayers_control_rotate',
      2 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotateandzoom',
      3 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(),
  );
  $export['openlayers_examples_map_atlas_webgl'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_icon_sprite';
  $ol_map->name = 'OpenLayers Examples Map Icon Sprite';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'renderer' => 'webgl',
    'width' => 'auto',
    'height' => '300px',
    'provideBlock' => 0,
    'provideBlockLayerSwitcher' => 0,
    'contextualLinks' => 0,
    'provideIframe' => 0,
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
      0 => 'openlayers_examples_layer_icon_sprite',
    ),
    'sources' => array(),
    'controls' => array(),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotateandzoom',
      3 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(),
  );
  $export['openlayers_examples_map_icon_sprite'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_openweather';
  $ol_map->name = 'OpenLayers Examples Map OpenWeather';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'renderer' => 'canvas',
    'width' => 'auto',
    'height' => '400px',
    'provideBlock' => 0,
    'provideBlockLayerSwitcher' => 0,
    'contextualLinks' => 0,
    'provideIframe' => 0,
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
      0 => 'openlayers_examples_layer_mapquest_sat',
      1 => 'openlayers_examples_layer_openweather_precipitation',
      2 => 'openlayers_examples_layer_openweather_precipitation_cls',
      3 => 'openlayers_examples_layer_openweather_clouds',
      4 => 'openlayers_examples_layer_openweather_clouds_cls',
      5 => 'openlayers_examples_layer_openweather_pressure',
      6 => 'openlayers_examples_layer_openweather_pressure_cntr',
      7 => 'openlayers_examples_layer_openweather_rain',
      8 => 'openlayers_examples_layer_openweather_rain_cls',
      9 => 'openlayers_examples_layer_openweather_temp',
      10 => 'openlayers_examples_layer_openweather_snow',
      11 => 'openlayers_examples_layer_openweather_wind',
    ),
    'controls' => array(
      0 => 'openlayers_control_fullscreen',
      1 => 'openlayers_control_rotate',
      2 => 'openlayers_control_zoom',
      3 => 'openlayers_examples_control_openweather_layer_switcher',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotateandzoom',
      3 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_openweather'] = $ol_map;

  return $export;
}
