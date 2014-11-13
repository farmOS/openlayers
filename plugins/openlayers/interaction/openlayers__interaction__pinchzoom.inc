<?php
/**
 * @file
 * Interaction: PinchZoom.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__interaction__pinchzoom_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => 'openlayers__interaction__pinchzoom',
      'file' => 'openlayers__interaction__pinchzoom.inc',
    ),
  );
}

/**
 * Class openlayers__interaction__pinchzoom.
 */
class openlayers__interaction__pinchzoom extends openlayers_interaction {

}
