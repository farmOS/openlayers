<?php
/**
 * @file
 * Layer: Image.
 */

namespace Drupal\openlayers\Layer;
use Drupal\openlayers\Types\Layer;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Layer\\Image',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class Image.
 */
class Image extends Layer {

}
