<?php
/**
 * @file
 * Source: KML.
 */

/**
 * Plugin definition.
 */
function openlayers_KML_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\KML',
    ),
  );
}
