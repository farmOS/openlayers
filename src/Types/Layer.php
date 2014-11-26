<?php
/**
 * @file
 * Class openlayers_layer.
 */

namespace Drupal\openlayers\Types;

/**
 * Class openlayers_layer.
 */
abstract class Layer extends Object implements LayerInterface {

  /**
   * Keeps track of what is attached.
   *
   * @var array
   */
  protected $attached = array();

  /**
   * Returns the source of this layer.
   *
   * @return openlayers_source_interface|FALSE
   *   The source assigned to this layer.
   */
  public function getSource() {
    if ($source = $this->getOption('source', FALSE)) {
      $this->objects['source'] = openlayers_object_load('source', $source);
      return $this->objects['source'];
    }
    return FALSE;
  }

  /**
   * Returns the style of this layer.
   *
   * @TODO Shouldn't this be part of the LayerInterface?
   *
   * @return openlayers_style_interface|FALSE
   *   The style assigned to this layer.
   */
  public function getStyle() {
    if ($style = $this->getOption('style', FALSE)) {
      $this->objects['style'] = openlayers_object_load('style', $style);
      return $this->objects['style'];
    }
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function develop() {
    if ($data = $this->getSource()) {
      $this->setOption('source', $data);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function preBuild(array &$build, \Drupal\openlayers\Types\ObjectInterface $context = NULL) {
    if ($source = $this->getSource()) {
      $source->preBuild($build, $context);
      drupal_alter('openlayers_object_preprocess', $source, $build);
      $this->setOption('source', $source);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, \Drupal\openlayers\Types\ObjectInterface $context = NULL) {
    if ($source = $this->getSource()) {
      $source->postBuild($build, $context);
      drupal_alter('openlayers_object_postprocess', $source, $build);
      $this->setOption('source', $source);
    }
  }
}
