<?php
/**
 * @file
 * Interaction: PinchZoom.
 */

/**
 * Plugin definition.
 */
function openlayers_pinchzoom_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\interaction\\pinchzoom',
    ),
  );
}
