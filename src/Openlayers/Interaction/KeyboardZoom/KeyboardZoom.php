<?php
/**
 * @file
 * Interaction: KeyboardZoom.
 */

namespace Drupal\openlayers\Interaction;
use Drupal\openlayers\Types\Interaction;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Interaction\\KeyboardZoom',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class KeyboardZoom.
 */
class KeyboardZoom extends Interaction {

}
