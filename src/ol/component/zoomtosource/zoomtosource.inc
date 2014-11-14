<?php
/**
 * @file
 * Component: ZoomSource.
 */

/**
 * Plugin definition.
 */
function openlayers_zoomtosource_openlayers_component() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\component\\zoomtosource',
    ),
  );
}
