<?php
/**
 * @file
 * Layer: Tile.
 */

/**
 * Plugin definition.
 */
function openlayers_Tile_openlayers_layer() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Layer\\Tile',
    ),
  );
}
