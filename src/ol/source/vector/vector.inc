<?php
/**
 * @file
 * Source: Vector.
 */

/**
 * Plugin definition.
 */
function openlayers_vector_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\source\\vector',
    ),
  );
}
