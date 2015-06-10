<?php
/**
 * @file
 * Control: Rotate.
 */

namespace Drupal\openlayers\Control;
use Drupal\openlayers\Types\Control;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Control\\Rotate',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class Rotate.
 */
class Rotate extends Control {

}
