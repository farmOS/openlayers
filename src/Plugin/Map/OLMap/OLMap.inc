<?php
/**
 * @file
 * Map: Map.
 */

/**
 * Plugin definition.
 */
function openlayers_OLMap_openlayers_map() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Map\\OLMap',
    ),
  );
}
