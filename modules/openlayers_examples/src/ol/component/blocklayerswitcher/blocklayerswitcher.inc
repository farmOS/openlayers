<?php
/**
 * @file
 * Component: Block Layer Switcher.
 */

/**
 * Plugin definition.
 */
function openlayers_examples_blocklayerswitcher_openlayers_component() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\component\\blocklayerswitcher',
    ),
  );
}
