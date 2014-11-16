<?php
/**
 * @file
 * Interaction: Draw.
 */

/**
 * Plugin definition.
 */
function openlayers_draw_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Interaction\\draw',
    ),
  );
}
