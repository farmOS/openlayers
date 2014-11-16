<?php
/**
 * @file
 * Interaction: MouseWheelZoom.
 */

/**
 * Plugin definition.
 */
function openlayers_mousewheelzoom_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Interaction\\mousewheelzoom',
    ),
  );
}
