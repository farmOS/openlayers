<?php
/**
 * @file
 * Interaction: Pointer.
 */

/**
 * Plugin definition.
 */
function openlayers_pointer_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\interaction\\pointer',
    ),
  );
}
