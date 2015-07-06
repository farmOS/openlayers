<?php
/**
 * @file
 * Class Layer.
 */

namespace Drupal\openlayers\Types;
use Drupal\openlayers\Openlayers;

/**
 * Class Layer.
 */
abstract class Layer extends Object implements LayerInterface {
  /**
   * {@inheritdoc}
   */
  public function buildCollection() {
    foreach (array('source', 'style') as $type) {
      if ($data = $this->getOption($type, FALSE)) {
        if ($object = Openlayers::load($type, $data)) {
          $this->getCollection()->merge($object->getCollection());
        }
      }
    }
    $this->getCollection()->append($this);
  }

  /**
   * Returns the source of this layer.
   *
   * @return SourceInterface|FALSE
   *   The source assigned to this layer.
   */
  public function getSource() {
    $source = $this->getObjects('source');
    if ($source = array_shift($source)) {
      return ($source instanceof SourceInterface) ? $source : FALSE;
    }
    return FALSE;
  }

  /**
   * Returns the style of this layer.
   *
   * @return StyleInterface|FALSE
   *   The style assigned to this layer.
   */
  public function getStyle() {
    $style = $this->getObjects('style');
    if ($style = array_shift($style)) {
      return ($style instanceof StyleInterface) ? $style : FALSE;
    }
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function getOptions() {
    $this->syncOptions();

    if ($source = $this->getSource()) {
      $this->setOption('source', $source->machine_name);
    }

    if ($style = $this->getStyle()) {
      $this->setOption('style', $style->machine_name);
    }

    return $this->configuration['options'];
  }

  /**
   * {@inheritdoc}
   */
  public function getJS() {
    $js = parent::getJS();

    foreach(Openlayers::getPluginTypes() as $type) {
      unset($js['opt'][$type . 's']);
    }

    return $js;
  }

}
