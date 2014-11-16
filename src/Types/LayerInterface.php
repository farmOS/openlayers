<?php
/**
 * @file
 * Interface openlayers_layer_interface.
 */

namespace Drupal\openlayers;

/**
 * Interface openlayers_layer_interface.
 */
interface LayerInterface {

  /**
   * Returns the source of this layer.
   *
   * @return openlayers_source_interface
   *   The source assigned to this layer.
   */
  public function getSource();
}
