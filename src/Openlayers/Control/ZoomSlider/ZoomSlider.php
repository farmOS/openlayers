<?php
/**
 * @file
 * Control: ZoomSlider.
 */

namespace Drupal\openlayers\Control;
use Drupal\openlayers\Types\Control;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Control\\ZoomSlider',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class ZoomSlider.
 */
class ZoomSlider extends Control {

}
