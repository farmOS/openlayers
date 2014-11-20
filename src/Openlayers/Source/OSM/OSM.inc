<?php
/**
 * @file
 * Source: OSM.
 */

/**
 * Plugin definition.
 */
function openlayers_OSM_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\OSM',
    ),
  );
}
