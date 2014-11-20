<?php
/**
 * @file
 * Interaction: DragBox.
 */

/**
 * Plugin definition.
 */
function openlayers_DragBox_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Interaction\\DragBox',
    ),
  );
}
