<?php
/**
 * @file
 * Source: Vector.
 */

namespace Drupal\openlayers\Source;
use Drupal\openlayers\Types\Source;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Source\\Vector',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class Vector.
 */
class Vector extends Source {

}
