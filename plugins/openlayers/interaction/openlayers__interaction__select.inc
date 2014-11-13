<?php
/**
 * @file
 * Interaction: Select.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__interaction__select_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => 'openlayers__interaction__select',
      'file' => 'openlayers__interaction__select.inc',
    ),
  );
}

/**
 * Class openlayers__interaction__select.
 */
class openlayers__interaction__select extends openlayers_interaction {

}
