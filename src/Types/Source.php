<?php
/**
 * @file
 * Class Source.
 */

namespace Drupal\openlayers\Types;

/**
 * Class Source.
 */
abstract class Source extends Object implements SourceInterface {
  /**
   * {@inheritdoc}
   */
  public function getJS() {
    $js = parent::getJS();

    unset($js['opt']['sources']);

    return $js;
  }
}
