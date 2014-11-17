<?php
/**
 * @file
 * Component: Graticule.
 */

/**
 * Plugin definition.
 */
function openlayers_Graticule_openlayers_component() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Component\\Graticule',
    ),
  );
}
