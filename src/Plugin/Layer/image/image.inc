<?php
/**
 * @file
 * Layer: Image.
 */

/**
 * Plugin definition.
 */
function openlayers_image_openlayers_layer() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Layer\\image',
    ),
  );
}
