<?php
/**
 * @file
 * Interaction: PinchZoom.
 */

namespace Drupal\openlayers\Interaction;
use Drupal\openlayers\Types\Interaction;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Interaction\\PinchZoom',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class PinchZoom.
 */
class PinchZoom extends Interaction {

}
