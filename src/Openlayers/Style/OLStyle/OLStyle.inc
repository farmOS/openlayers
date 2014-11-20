<?php
/**
 * @file
 * Style: Style.
 */

/**
 * Plugin definition.
 */
function openlayers_OLStyle_openlayers_style() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Style\\OLStyle',
    ),
  );
}
