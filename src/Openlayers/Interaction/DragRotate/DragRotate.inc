<?php
/**
 * @file
 * Interaction: DragRotate.
 */

/**
 * Plugin definition.
 */
function openlayers_DragRotate_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Interaction\\DragRotate',
    ),
  );
}
