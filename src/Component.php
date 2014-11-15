<?php
/**
 * @file
 * Class openlayers_component.
 */

namespace Drupal\openlayers;

/**
 * Class openlayers_component.
 */
abstract class Component extends Object implements ComponentInterface {
  public function getType() {
    return 'component';
  }
}
