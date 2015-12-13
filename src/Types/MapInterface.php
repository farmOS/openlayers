<?php
/**
 * @file
 * Interface MapInterface.
 */

namespace Drupal\openlayers\Types;

/**
 * Interface MapInterface.
 */
interface MapInterface extends ObjectInterface {
  /**
   * Returns the id of this map.
   *
   * @return string
   *   The id of this map.
   */
  public function getId();

  /**
   * Add a layer to the map.
   *
   * @param LayerInterface $layer
   *   The layer object to add.
   */
  public function addLayer(LayerInterface $layer);

  /**
   * Add a control to the map.
   *
   * @param ControlInterface $control
   *   The control object to add.
   */
  public function addControl(ControlInterface $control);

  /**
   * Add an interaction to the map.
   *
   * @param InteractionInterface $interaction
   *   The interaction object to add.
   */
  public function addInteraction(InteractionInterface $interaction);

  /**
   * Add a component to the map.
   *
   * @param ComponentInterface $component
   *   The component object to add.
   */
  public function addComponent(ComponentInterface $component);

  /**
   * Build render array of a map.
   *
   * @param array $build
   *   The build array before being completed.
   *
   * @return array
   *   The render array.
   */
  public function build(array $build = array());

}
