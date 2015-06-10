<?php
/**
 * @file
 * Interaction: DragBox.
 */

namespace Drupal\openlayers\Interaction;
use Drupal\openlayers\Types\Interaction;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Interaction\\DragBox',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class DragBox.
 *
 * @package Drupal\openlayers\Interaction
 */
class DragBox extends Interaction {

}
