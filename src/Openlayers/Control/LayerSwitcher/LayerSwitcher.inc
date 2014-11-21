<?php
/**
 * @file
 * Control: LayerSwitcher.
 */

/**
 * Plugin definition.
 */
function openlayers_layerswitcher_openlayers_control() {
  return array(
      'class' => '\\Drupal\\openlayers\\Control\\LayerSwitcher',
  );
}
