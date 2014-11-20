<?php
/**
 * @file
 * Source: Vector.
 */

/**
 * Plugin definition.
 */
function openlayers_Vector_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\Vector',
    ),
  );
}
