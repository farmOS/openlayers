<?php
/**
 * @file
 * Source: TileDebug.
 */

/**
 * Plugin definition.
 */
function openlayers_TileDebug_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\TileDebug',
    ),
  );
}
