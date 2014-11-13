<?php
/**
 * @file
 * Interaction: Draw.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__interaction__draw_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => 'openlayers__interaction__draw',
      'file' => 'openlayers__interaction__draw.inc',
    ),
  );
}

/**
 * Class openlayers__interaction__draw.
 */
class openlayers__interaction__draw extends openlayers_interaction {

}
