<?php
/**
 * @file
 * Layer: JS.
 */

/**
 * Plugin definition.
 */
function openlayers_InlineJS_openlayers_layer() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Layer\\InlineJS',
    ),
  );
}
