<?php
/**
 * @file
 * Source: KML.
 */

namespace Drupal\openlayers\Source;
use Drupal\openlayers\Source;

/**
 * Class KML.
 */
class KML extends Source {

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
