<?php
/**
 * @file
 * Source: Mapquest.
 */

/**
 * Plugin definition.
 */
function openlayers_mapquest_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\source\\mapquest',
    ),
  );
}
