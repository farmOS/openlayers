<?php
/**
 * @file
 * Source: ImageStatic.
 */

/**
 * Plugin definition.
 */
function openlayers_ImageStatic_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\ImageStatic',
    ),
  );
}
