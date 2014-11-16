<?php
/**
 * @file
 * Source: BingMaps.
 */

/**
 * Plugin definition.
 */
function openlayers_bingmaps_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\bingmaps',
    ),
  );
}
