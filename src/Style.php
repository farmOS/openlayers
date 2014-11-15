<?php
/**
 * @file
 * Class openlayers_style.
 */

namespace Drupal\openlayers;

/**
 * Class openlayers_style.
 */
abstract class Style extends Object implements StyleInterface {
  public function getType() {
    return 'style';
  }
}
