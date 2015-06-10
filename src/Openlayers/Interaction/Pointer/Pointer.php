<?php
/**
 * @file
 * Interaction: Pointer.
 */

namespace Drupal\openlayers\Interaction;
use Drupal\openlayers\Types\Interaction;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Interaction\\Pointer',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class Pointer.
 */
class Pointer extends Interaction {

}
