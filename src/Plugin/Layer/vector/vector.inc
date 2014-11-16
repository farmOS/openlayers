<?php
/**
 * @file
 * Layer: Vector.
 */

/**
 * Plugin definition.
 */
function openlayers_vector_openlayers_layer() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Layer\\vector',
    ),
  );
}

