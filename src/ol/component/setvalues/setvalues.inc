<?php
/**
 * @file
 * Component: SetValues.
 */

/**
 * Plugin definition.
 */
function openlayers_setvalues_openlayers_component() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\component\\setvalues',
    ),
  );
}
