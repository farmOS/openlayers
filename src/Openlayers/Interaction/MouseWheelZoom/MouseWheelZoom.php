<?php
/**
 * @file
 * Interaction: MouseWheelZoom.
 */

namespace Drupal\openlayers\Interaction;
use Drupal\openlayers\Types\Interaction;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Interaction\\MouseWheelZoom',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class MouseWheelZoom.
 */
class MouseWheelZoom extends Interaction {

}
