<?php
/**
 * @file
 * Source: Mapquest.
 */

/**
 * Plugin definition.
 */
function openlayers_MapQuest_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\MapQuest',
    ),
  );
}
