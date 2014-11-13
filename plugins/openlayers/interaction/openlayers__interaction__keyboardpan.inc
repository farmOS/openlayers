<?php
/**
 * @file
 * Interaction: KeyboardPan.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__interaction__keyboardpan_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => 'openlayers__interaction__keyboardpan',
      'file' => 'openlayers__interaction__keyboardpan.inc',
    ),
  );
}

/**
 * Class openlayers__interaction__keyboardpan.
 */
class openlayers__interaction__keyboardpan extends openlayers_interaction {

}
