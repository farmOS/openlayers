<?php
/**
 * @file
 * Class openlayers_projection.
 */

namespace Drupal\openlayers;

/**
 * Class openlayers_projection.
 */
abstract class Projection extends Object implements ProjectionInterface {
  public function getType() {
    return 'Projection';
  }
}