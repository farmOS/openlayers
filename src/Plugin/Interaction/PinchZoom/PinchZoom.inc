<?php
/**
 * @file
 * Interaction: PinchZoom.
 */

/**
 * Plugin definition.
 */
function openlayers_PinchZoom_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Interaction\\PinchZoom',
    ),
  );
}
