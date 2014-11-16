<?php
/**
 * @file
 * Interaction: KeyboardPan.
 */

/**
 * Plugin definition.
 */
function openlayers_keyboardpan_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Interaction\\keyboardpan',
    ),
  );
}
