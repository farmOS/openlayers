<?php
/**
 * @file
 * Component: ZoomSource.
 */

/**
 * Plugin definition.
 */
function openlayers_ZoomToSource_openlayers_component() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Component\\ZoomToSource',
    ),
  );
}
