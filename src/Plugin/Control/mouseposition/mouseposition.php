<?php
/**
 * @file
 * Control: MousePosition.
 */

namespace Drupal\openlayers\Control;
use Drupal\openlayers\Control;

/**
 * Class openlayers__control__mouseposition.
 */
class mouseposition extends Control {

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    $form['options']['target'] = array(
      '#type' => 'textfield',
      '#title' => t('ID of the element.'),
      '#default_value' => $this->getOption('target'),
    );
    $form['options']['undefinedHTML'] = array(
      '#type' => 'textfield',
      '#title' => t('undefinedHTML'),
      '#default_value' => $this->getOption('undefinedHTML'),
      '#description' => t('Markup for undefined coordinates. Default is an empty string.'),
    );
  }

}
