<?php
/**
 * @file
 * Interface LayerInterface.
 */

namespace Drupal\openlayers\Types;

/**
 * Interface LayerInterface.
 */
interface LayerInterface extends ObjectInterface {

  /**
   * Returns the source of this layer.
   *
   * @return SourceInterface|FALSE
   *   The source assigned to this layer.
   */
  public function getSource();
}
