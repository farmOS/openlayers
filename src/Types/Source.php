<?php
/**
 * @file
 * Class Source.
 */

namespace Drupal\openlayers\Types;
use Drupal\openlayers\Openlayers;

/**
 * Class Source.
 */
abstract class Source extends Object implements SourceInterface {
  /**
   * {@inheritdoc}
   */
  public function buildCollection() {
    foreach ((array) $this->getOption('sources', array()) as $weight => $object) {
      if (($merge_object = Openlayers::load('source', $object)) == TRUE) {
        $merge_object->setWeight($weight);
        $this->getCollection()->merge($merge_object->getCollection());
      }
    }
    parent::buildCollection();
  }

  /**
   * {@inheritdoc}
   */
  public function getJS() {
    $js = parent::getJS();

    unset($js['opt']['sources']);

    return $js;
  }
}
