<?php
/**
 * @file
 * Interaction: KeyboardPan.
 */

namespace Drupal\openlayers\Interaction;
use Drupal\openlayers\Types\Interaction;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Interaction\\KeyboardPan',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class KeyboardPan.
 */
class KeyboardPan extends Interaction {

}
