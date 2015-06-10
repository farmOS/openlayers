<?php
/**
 * @file
 * Source: TileUTFGrid.
 */

namespace Drupal\openlayers\Source;
use Drupal\openlayers\Types\Source;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Source\\TileUTFGrid',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class TileUTFGrid.
 */
class TileUTFGrid extends Source {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['url'] = array(
      '#title' => t('URL'),
      '#type' => 'textfield',
      '#default_value' => $this->getOption('url'),
    );
  }

}
