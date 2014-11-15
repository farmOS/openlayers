<?php
/**
 * @file
 * Interaction: Modify.
 */

/**
 * Plugin definition.
 */
function openlayers_modify_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\interaction\\modify',
    ),
  );
}
