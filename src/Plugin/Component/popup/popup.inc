<?php
/**
 * @file
 * Component: Popup.
 */

/**
 * Plugin definition.
 */
function openlayers_popup_openlayers_component() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Component\\popup',
    ),
  );
}
