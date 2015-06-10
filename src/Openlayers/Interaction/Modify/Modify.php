<?php
/**
 * @file
 * Interaction: Modify.
 */

namespace Drupal\openlayers\Interaction;
use Drupal\openlayers\Types\Interaction;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Interaction\\Modify',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class Modify.
 */
class Modify extends Interaction {

}
