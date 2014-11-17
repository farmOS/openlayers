<?php
/**
 * @file
 * Source: BingMaps.
 */

/**
 * Plugin definition.
 */
function openlayers_BingMaps_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\BingMaps',
    ),
  );
}
