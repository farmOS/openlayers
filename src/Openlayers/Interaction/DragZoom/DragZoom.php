<?php
/**
 * @file
 * Interaction: DragZoom.
 */

namespace Drupal\openlayers\Interaction;
use Drupal\openlayers\Types\Interaction;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Interaction\\DragZoom',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class DragZoom.
 *
 * @package Drupal\openlayers\Interaction
 */
class DragZoom extends Interaction {

}
