<?php
/**
 * @file
 * Source: TileJson.
 */

/**
 * Plugin definition.
 */
function openlayers_TileJSON_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\TileJSON',
    ),
  );
}
