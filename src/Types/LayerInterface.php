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
   *   The source of this layer.
   */
  public function getSource();

  /**
   * Set the source of this layer.
   *
   * @param SourceInterface $source
   *   The source object.
   *
   * @return LayerInterface
   *   The parent layer.
   */
  public function setSource(SourceInterface $source);

  /**
   * Returns the style of this layer.
   *
   * @return StyleInterface|FALSE
   *   The style of this layer.
   */
  public function getStyle();

  /**
   * Set the style of this layer.
   *
   * @param StyleInterface $style
   *   The style object.
   *
   * @return LayerInterface
   *   The parent layer.
   */
  public function setStyle(StyleInterface $style);

}
