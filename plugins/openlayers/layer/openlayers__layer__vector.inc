<?php
/**
 * @file
 * Layer: Vector.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__layer__vector_openlayers_layer() {
  return array(
    'handler' => array(
      'class' => 'openlayers__layer__vector',
      'file' => 'openlayers__layer__vector.inc',
    ),
  );
}

/**
 * Class openlayers__layer__vector.
 */
class openlayers__layer__vector extends openlayers_layer {

}
