<?php
/**
 * @file
 * Source: GeoJson.
 */

/**
 * Plugin definition.
 */
function openlayers_geojson_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\geojson',
    ),
  );
}
