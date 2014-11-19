<?php
/**
 * @file
 * Interaction: DragZoom.
 */

/**
 * Plugin definition.
 */
function openlayers_DragZoom_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Interaction\\DragZoom',
    ),
  );
}
