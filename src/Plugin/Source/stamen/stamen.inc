<?php
/**
 * @file
 * Source: Stamen.
 */

/**
 * Plugin definition.
 */
function openlayers_stamen_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\stamen',
    ),
  );
}
