<?php
/**
 * @file
 * Layer: Image.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__layer__image_openlayers_layer() {
  return array(
    'handler' => array(
      'class' => 'openlayers__layer__image',
      'file' => 'openlayers__layer__image.inc',
    ),
  );
}

/**
 * Class openlayers__layer__image.
 */
class openlayers__layer__image extends openlayers_layer {

}
