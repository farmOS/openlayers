<?php
/**
 * @file
 * Interaction: KeyboardZoom.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__interaction__keyboardzoom_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => 'openlayers__interaction__keyboardzoom',
      'file' => 'openlayers__interaction__keyboardzoom.inc',
    ),
  );
}

/**
 * Class openlayers__interaction__keyboardzoom.
 */
class openlayers__interaction__keyboardzoom extends openlayers_interaction {

}
