<?php
/**
 * @file
 * Style: ClusterStyle.
 */

namespace Drupal\openlayers\Style;
use Drupal\openlayers\Types\Style;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Style\\ClusterStyle',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class ClusterStyle.
 */
class ClusterStyle extends Style {
  //TODO: Provide options to let user customize the cluster style.
}
