<?php
/**
 * @file
 * Source: OSM.
 */

/**
 * Plugin definition.
 */
function openlayers_osm_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\source\\osm',
    ),
  );
}
