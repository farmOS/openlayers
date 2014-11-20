<?php
/**
 * @file
 * Interface openlayers_layer_interface.
 */

namespace Drupal\openlayers\Types;

/**
 * Interface openlayers_layer_interface.
 */
interface LayerInterface {

  /**
   * Returns the source of this layer.
   *
   * @return openlayers_source_interface|FALSE
   *   The source assigned to this layer.
   */
  public function getSource();

  /**
   * Returns a list of attachments for building the render array.
   *
   * @param \Drupal\openlayers\Types\ObjectInterface $context
   *   The object the attachments are attached to.
   *
   * @return array
   *   The attachments to add.
   */
  public function attached(\Drupal\openlayers\Types\ObjectInterface $context);
}
