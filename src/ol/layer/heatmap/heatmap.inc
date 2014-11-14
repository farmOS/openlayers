<?php
/**
 * @file
 * Layer: Heatmap.
 */

/**
 * Plugin definition.
 */
function openlayers_heatmap_openlayers_layer() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\layer\\heatmap',
    ),
  );
}
