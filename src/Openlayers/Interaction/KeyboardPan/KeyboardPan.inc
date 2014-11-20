<?php
/**
 * @file
 * Interaction: KeyboardPan.
 */

/**
 * Plugin definition.
 */
function openlayers_KeyboardPan_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Interaction\\KeyboardPan',
    ),
  );
}
