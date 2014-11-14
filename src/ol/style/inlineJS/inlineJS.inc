<?php
/**
 * @file
 * Style: JS.
 */

/**
 * Plugin definition.
 */
function openlayers_inlineJS_openlayers_style() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\style\\inlineJS',
    ),
  );
}
