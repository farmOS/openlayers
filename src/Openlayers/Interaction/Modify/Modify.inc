<?php
/**
 * @file
 * Interaction: Modify.
 */

/**
 * Plugin definition.
 */
function openlayers_Modify_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Interaction\\Modify',
    ),
  );
}