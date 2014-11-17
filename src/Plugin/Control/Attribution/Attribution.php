<?php
/**
 * @file
 * Control: Attribution.
 */

namespace Drupal\openlayers\Control;
use Drupal\openlayers\Control;

/**
 * Class openlayers__control__attribution.
 */
class attribution extends Control {

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    $form['options']['collapsible'] = array(
      '#type' => 'checkbox',
      '#title' => t('Collapsible'),
      '#default_value' => $this->getOption('collapsible'),
    );
  }

}
