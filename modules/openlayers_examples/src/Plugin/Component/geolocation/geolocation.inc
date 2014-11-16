<?php
/**
 * @file
 * Component: Geolocation.
 */

/**
 * Plugin definition.
 */
function openlayers_examples_geolocation_openlayers_component() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Component\\geolocation',
    ),
  );
}
