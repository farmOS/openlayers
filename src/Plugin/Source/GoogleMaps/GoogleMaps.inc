<?php
/**
 * @file
 * Google maps API integration based on the example here:
 * http://openlayers.org/en/v3.0.0/examples/google-map.html
 * http://bl.ocks.org/elemoine/e82c7dd4b1d0ef45a9a4
 */

/**
 * Defines the google source handler plugin.
 *
 * @return array
 *   The plugin data.
 */
function openlayers_GoogleMaps_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\GoogleMaps',
    ),
  );
}
