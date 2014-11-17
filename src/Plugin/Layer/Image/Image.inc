<?php
/**
 * @file
 * Layer: Image.
 */

/**
 * Plugin definition.
 */
function openlayers_Image_openlayers_layer() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Layer\\Image',
    ),
  );
}
