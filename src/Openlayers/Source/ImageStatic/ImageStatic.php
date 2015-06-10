<?php
/**
 * @file
 * Source: ImageStatic.
 */

namespace Drupal\openlayers\Source;
use Drupal\openlayers\Types\Source;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Source\\ImageStatic',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class ImageStatic.
 *
 * @package Drupal\openlayers\Source
 */
class ImageStatic extends Source {

}
