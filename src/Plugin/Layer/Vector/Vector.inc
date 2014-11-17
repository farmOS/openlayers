<?php
/**
 * @file
 * Layer: Vector.
 */

/**
 * Plugin definition.
 */
function openlayers_Vector_openlayers_layer() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Layer\\Vector',
    ),
  );
}

