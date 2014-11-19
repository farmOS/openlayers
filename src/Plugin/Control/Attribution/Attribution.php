<?php
/**
 * @file
 * Control: Attribution.
 */

namespace Drupal\openlayers\Control;
use Drupal\openlayers\Control;

/**
 * Class Attribution.
 */
class Attribution extends Control {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['collapsible'] = array(
      '#type' => 'checkbox',
      '#title' => t('Collapsible'),
      '#default_value' => $this->getOption('collapsible'),
    );
  }

}
