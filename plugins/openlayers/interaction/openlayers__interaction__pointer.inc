<?php
/**
 * @file
 * Interaction: Pointer.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__interaction__pointer_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => 'openlayers__interaction__pointer',
      'file' => 'openlayers__interaction__pointer.inc',
    ),
  );
}

/**
 * Class openlayers__interaction__pointer.
 */
class openlayers__interaction__pointer extends openlayers_interaction {

}
