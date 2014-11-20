<?php
/**
 * @file
 * Interaction: DragRotateAndZoom.
 */

/**
 * Plugin definition.
 */
function openlayers_DragRotateAndZoom_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Interaction\\DragRotateAndZoom',
    ),
  );
}
