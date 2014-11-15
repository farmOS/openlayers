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
      'class' => '\\Drupal\\openlayers\\source\\geojson',
  );
}
