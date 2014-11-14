<?php
/**
 * @file
 * Control: Attribution.
 */

/**
 * Plugin definition.
 */
function openlayers_inlineJS_openlayers_control() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\control\\inlineJS',
    ),
  );
}
