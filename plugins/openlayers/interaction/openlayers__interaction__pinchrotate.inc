<?php
/**
 * @file
 * Interaction: PinchRotate.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__interaction__pinchrotate_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => 'openlayers__interaction__pinchrotate',
      'file' => 'openlayers__interaction__pinchrotate.inc',
    ),
  );
}

/**
 * Class openlayers__interaction__pinchrotate.
 */
class openlayers__interaction__pinchrotate extends openlayers_interaction {

}
