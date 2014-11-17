<?php
/**
 * @file
 * Source: XYZ.
 */

/**
 * Plugin definition.
 */
function openlayers_XYZ_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\XYZ',
    ),
  );
}
