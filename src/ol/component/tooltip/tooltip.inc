<?php
/**
 * @file
 * Component: Tooltip.
 */

/**
 * Plugin definition.
 */
function openlayers_tooltip_openlayers_component() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\component\\tooltip',
    ),
  );
}
