<?php
/**
 * @file
 * Component: JS Component.
 */

/**
 * Plugin definition.
 */
function openlayers_inlineJS_openlayers_component() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\component\\inlineJS',
    ),
  );
}
