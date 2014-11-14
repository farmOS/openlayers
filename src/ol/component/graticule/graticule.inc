<?php
/**
 * @file
 * Component: Graticule.
 */

/**
 * Plugin definition.
 */
function openlayers_graticule_openlayers_component() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\component\\graticule',
    ),
  );
}
