<?php
/**
 * @file
 * Control: ZoomExtent.
 */

namespace Drupal\openlayers\Control;
use Drupal\openlayers\Types\Control;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Control\\ZoomToExtent',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class ZoomToExtent.
 */
class ZoomToExtent extends Control {

}
