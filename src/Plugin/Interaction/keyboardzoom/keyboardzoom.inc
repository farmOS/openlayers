<?php
/**
 * @file
 * Interaction: KeyboardZoom.
 */

/**
 * Plugin definition.
 */
function openlayers_keyboardzoom_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Interaction\\keyboardzoom',
    ),
  );
}
