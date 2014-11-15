<?php
/**
 * @file
 * Interaction: PinchRotate.
 */

/**
 * Plugin definition.
 */
function openlayers_pinchrotate_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\interaction\\pinchrotate',
    ),
  );
}
