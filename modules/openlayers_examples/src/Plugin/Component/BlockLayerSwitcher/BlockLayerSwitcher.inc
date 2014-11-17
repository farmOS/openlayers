<?php
/**
 * @file
 * Component: Block Layer Switcher.
 */

/**
 * Plugin definition.
 */
function openlayers_examples_BlockLayerSwitcher_openlayers_component() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Component\\BlockLayerSwitcher',
    ),
  );
}
