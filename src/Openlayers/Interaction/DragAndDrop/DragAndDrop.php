<?php
/**
 * @file
 * Interaction: DragAndDrop.
 */

namespace Drupal\openlayers\Interaction;
use Drupal\openlayers\Types\Interaction;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Interaction\\DragAndDrop',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class DragAndDrop.
 *
 * @package Drupal\openlayers\Interaction
 */
class DragAndDrop extends Interaction {

}
