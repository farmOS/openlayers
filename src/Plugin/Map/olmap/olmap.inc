<?php
/**
 * @file
 * Map: Map.
 */

/**
 * Plugin definition.
 */
function openlayers_olmap_openlayers_map() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Map\\olmap',
    ),
  );
}
