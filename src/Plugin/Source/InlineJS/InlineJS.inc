<?php
/**
 * @file
 * Source: JS.
 */

/**
 * Plugin definition.
 */
function openlayers_InlineJS_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\InlineJS',
    ),
  );
}
