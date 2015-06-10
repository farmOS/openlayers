<?php
/**
 * @file
 * Control: Fullscreen.
 */

namespace Drupal\openlayers\Control;
use Drupal\openlayers\Types\Control;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Control\\FullScreen',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class FullScreen.
 */
class FullScreen extends Control {

}
