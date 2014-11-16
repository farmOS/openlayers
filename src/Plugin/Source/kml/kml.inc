<?php
/**
 * @file
 * Source: KML.
 */

/**
 * Plugin definition.
 */
function openlayers_kml_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\kml',
    ),
  );
}
