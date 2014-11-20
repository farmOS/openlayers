<?php
/**
 * @file
 * Interaction: DragPan.
 */

/**
 * Plugin definition.
 */
function openlayers_DragPan_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Interaction\\DragPan',
    ),
  );
}
