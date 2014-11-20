<?php
/**
 * @file
 * Component: JS Component.
 */

/**
 * Plugin definition.
 */
function openlayers_InlineJS_openlayers_component() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Component\\InlineJS',
    ),
  );
}
