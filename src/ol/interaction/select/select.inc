<?php
/**
 * @file
 * Interaction: Select.
 */

/**
 * Plugin definition.
 */
function openlayers_select_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\interaction\\select',
    ),
  );
}
