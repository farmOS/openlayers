<?php
/**
 * @file
 * Source: TileDebug.
 */

namespace Drupal\openlayers\Source;
use Drupal\openlayers\Types\Source;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Source\\TileDebug',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class TileDebug.
 */
class TileDebug extends Source {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['maxZoom'] = array(
      '#title' => t('Maxzoom'),
      '#type' => 'textfield',
      '#default_value' => $this->getOption('maxZoom', 22),
    );
  }

}
