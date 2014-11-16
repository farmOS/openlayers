<?php
/**
 * @file
 * Source: TileDebug.
 */

/**
 * Plugin definition.
 */
function openlayers_tiledebug_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\tiledebug',
    ),
  );
}
