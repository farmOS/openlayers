<?php
/**
 * @file
 * Source: ImageVector.
 */

/**
 * Plugin definition.
 */
function openlayers_imagevector_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\imagevector',
    ),
  );
}
