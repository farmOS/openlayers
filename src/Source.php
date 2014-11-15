<?php
/**
 * @file
 * Class openlayers_source.
 */

namespace Drupal\openlayers;

/**
 * Class openlayers_source.
 */
abstract class Source extends Object implements SourceInterface {
  public function getType() {
    return 'source';
  }
}
