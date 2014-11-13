<?php
/**
 * @file
 * Control: Fullscreen.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__control__fullscreen_openlayers_control() {
  return array(
    'handler' => array(
      'class' => 'openlayers__control__fullscreen',
      'file' => 'openlayers__control__fullscreen.inc',
    ),
  );
}

/**
 * Class openlayers__control__fullscreen.
 */
class openlayers__control__fullscreen extends openlayers_control {


}
