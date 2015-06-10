<?php
/**
 * @file
 * Interaction: PinchRotate.
 */

namespace Drupal\openlayers\Interaction;
use Drupal\openlayers\Types\Interaction;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Interaction\\PinchRotate',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class PinchRotate.
 */
class PinchRotate extends Interaction {

}
