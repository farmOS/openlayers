<?php
/**
 * @file
 * Interaction: DragRotate.
 */

namespace Drupal\openlayers\Interaction;
use Drupal\openlayers\Types\Interaction;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Interaction\\DragRotate',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class DragRotate.
 *
 * @package Drupal\openlayers\Interaction
 */
class DragRotate extends Interaction {

}
