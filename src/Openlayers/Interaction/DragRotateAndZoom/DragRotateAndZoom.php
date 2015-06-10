<?php
/**
 * @file
 * Interaction: DragRotateAndZoom.
 */

namespace Drupal\openlayers\Interaction;
use Drupal\openlayers\Types\Interaction;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Interaction\\DragRotateAndZoom',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class DragRotateAndZoom.
 *
 * @package Drupal\openlayers\Interaction
 */
class DragRotateAndZoom extends Interaction {

}
