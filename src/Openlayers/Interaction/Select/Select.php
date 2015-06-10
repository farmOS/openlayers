<?php
/**
 * @file
 * Interaction: Select.
 */

namespace Drupal\openlayers\Interaction;
use Drupal\openlayers\Types\Interaction;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Interaction\\Select',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class Select.
 */
class Select extends Interaction {

}
