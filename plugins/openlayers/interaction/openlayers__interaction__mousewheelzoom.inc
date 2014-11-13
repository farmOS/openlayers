<?php
/**
 * @file
 * Interaction: MouseWheelZoom.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__interaction__mousewheelzoom_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => 'openlayers__interaction__mousewheelzoom',
      'file' => 'openlayers__interaction__mousewheelzoom.inc',
    ),
  );
}

/**
 * Class openlayers__interaction__mousewheelzoom.
 */
class openlayers__interaction__mousewheelzoom extends openlayers_interaction {

}
