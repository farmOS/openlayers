<?php
/**
 * @file
 * Style: Style.
 */

/**
 * Plugin definition.
 */
function openlayers_olstyle_openlayers_style() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\style\\olstyle',
    ),
  );
}
