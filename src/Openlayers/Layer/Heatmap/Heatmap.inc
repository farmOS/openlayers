<?php
/**
 * @file
 * Layer: Heatmap.
 */

/**
 * Plugin definition.
 */
function openlayers_Heatmap_openlayers_layer() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Layer\\Heatmap',
    ),
  );
}
