<?php
/**
 * @file
 * Interaction: Draw.
 */

namespace Drupal\openlayers\Interaction;
use Drupal\openlayers\Types\Interaction;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Interaction\\Draw',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class Draw.
 */
class Draw extends Interaction {

}
