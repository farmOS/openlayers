<?php
/**
 * @file
 * Source: XYZ.
 */

/**
 * Plugin definition.
 */
function openlayers_xyz_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\source\\xyz',
    ),
  );
}
