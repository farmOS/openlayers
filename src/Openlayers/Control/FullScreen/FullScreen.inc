<?php
/**
 * @file
 * Control: Attribution.
 */

/**
 * Plugin definition.
 */
function openlayers_FullScreen_openlayers_control() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Control\\FullScreen',
    ),
  );
}
