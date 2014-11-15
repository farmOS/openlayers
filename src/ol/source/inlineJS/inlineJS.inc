<?php
/**
 * @file
 * Source: JS.
 */

/**
 * Plugin definition.
 */
function openlayers_inlineJS_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\source\\inlineJS',
    ),
  );
}
