<?php
/**
 * @file
 * Component: Autopopup.
 */

/**
 * Plugin definition.
 */
function openlayers_autopopup_openlayers_component() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Component\\autopopup',
    ),
  );
}
