<?php
/**
 * @file
 * Class openlayers_layer.
 */

namespace Drupal\openlayers;

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
   * {@inheritdoc}
   */
  public function getSource() {
    if ($source = $this->getOption('source')) {
      return openlayers_object_load('source', $this->getOption('source'));
    }
    return FALSE;
  }

  /**
   * Returns the source of this layer.
   *
   * @TODO Shouldn't this be part of the LayerInterface?
   *
   * @return openlayers_style_interface|FALSE
   *   The source assigned to this layer.
   */
  public function getStyle() {
    if ($style = $this->getOption('style')) {
      return openlayers_object_load('style', $this->getOption('style'));
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
  public function preBuild(array &$build, \Drupal\openlayers\ObjectInterface $context = NULL) {
    if ($source = $this->getSource()) {
      $source->preBuild($build, $context);
      drupal_alter('openlayers_object_preprocess', $source, $build);
      $this->setOption('source', $source);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, \Drupal\openlayers\ObjectInterface $context = NULL) {
    if ($source = $this->getSource()) {
      $source->postBuild($build, $context);
      drupal_alter('openlayers_object_postprocess', $source, $build);
      $this->setOption('source', $source);
    }
  }
}
