<?php
/**
 * @file
 * Control: ScaleLine.
 */

namespace Drupal\openlayers\Control;
use Drupal\openlayers\Types\Control;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Control\\ScaleLine',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class ScaleLine.
 */
class ScaleLine extends Control {

}
