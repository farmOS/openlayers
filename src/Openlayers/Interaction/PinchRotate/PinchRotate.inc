<?php
/**
 * @file
 * Interaction: PinchRotate.
 */

/**
 * Plugin definition.
 */
function openlayers_PinchRotate_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Interaction\\PinchRotate',
    ),
  );
}
