<?php
/**
 * @file
 * Interface openlayers_layer_interface.
 */

/**
 * Interface openlayers_layer_interface.
 */
interface openlayers_layer_interface {

  /**
   * Returns the source of this layer.
   *
   * @return openlayers_source_interface
   *   The source assigned to this layer.
   */
  public function getSource();
}
