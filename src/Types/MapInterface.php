<?php
/**
 * @file
 * Interface openlayers_map_interface.
 */

namespace Drupal\openlayers\Types;

/**
 * Interface openlayers_map_interface.
 */
interface MapInterface {
  /**
   * Returns the id of this map.
   *
   * @return string
   *   The id of this map.
   */
  public function getId();

  /**
   * Returns an array of objects assigned to this map.
   *
   * @return array
   *   Associative array of objects assigned to this map. Keyed by the type of
   *   the objects.
   */
  public function &getObjects();

  /**
   * Returns an JS compatible array of objects assigned to this map.
   *
   * @return array
   *   JS compatible array of objects assigned to this map. Keyed by the type of
   *   the objects.
   */
  public function getJSObjects();

  /**
   * Returns the layer objects assigned to this map.
   *
   * @return array
   *   List of layer objects assigned to this map.
   */
  public function getLayers();

  /**
   * Returns the source objects assigned to this map.
   *
   * @return array
   *   List of source objects assigned to this map.
   */
  public function getSources();

  /**
   * Returns the control objects assigned to this map.
   *
   * @return array
   *   List of control objects assigned to this map.
   */
  public function getControls();

  /**
   * Returns the interaction objects assigned to this map.
   *
   * @return array
   *   List of interaction objects assigned to this map.
   */
  public function getInteractions();

  /**
   * Returns the component objects assigned to this map.
   *
   * @return array
   *   List of component objects assigned to this map.
   */
  public function getComponents();

  /**
   * Build render array of a map.
   *
   * @return array
   */
  public function build();

  /**
   * Invoked before an objects render array is built.
   *
   * Mostly invoked by the map object.
   *
   * @param array $build
   *   The array with the build information.
   * @param \Drupal\openlayers\Types\ObjectInterface $context
   *   The context of the build. Mostly the map object.
   */
  public function preBuild(array &$build, \Drupal\openlayers\Types\ObjectInterface $context = NULL);

  /**
   * Invoked after an objects render array is built.
   *
   * Mostly invoked by the map object.
   *
   * @param array $build
   *   The array with the build information.
   * @param \Drupal\openlayers\Types\ObjectInterface $context
   *   The context of the build. Mostly the map object.
   */
  public function postBuild(array &$build, \Drupal\openlayers\Types\ObjectInterface $context = NULL);
  }
