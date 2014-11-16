<?php
/**
 * @file
 * Map: Views.
 */

/**
 * Plugin definition.
 */
function openlayers_views_views_openlayers_map() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Map\\views',
    ),
  );
}
