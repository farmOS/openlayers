<?php
/**
 * @file
 * Control: Zoom.
 */

namespace Drupal\openlayers\Control;
use Drupal\openlayers\Types\Control;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Control\\Zoom',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class Zoom.
 */
class Zoom extends Control {

}
