<?php
/**
 * @file
 * Layer: Geofield.
 */

namespace Drupal\openlayers\Layer;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Layer\\Geofield',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class Geofield.
 */
class Geofield extends Vector {

}
