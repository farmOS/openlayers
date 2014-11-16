<?php
/**
 * @file
 * Component: Geofield.
 */

/**
 * Plugin definition.
 */
function openlayers_examples_geofield_openlayers_component() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Component\\geofield',
    ),
  );
}
