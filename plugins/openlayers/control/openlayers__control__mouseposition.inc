<?php
/**
 * @file
 * Control: MousePosition.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__control__mouseposition_openlayers_control() {
  return array(
    'handler' => array(
      'class' => 'openlayers__control__mouseposition',
      'file' => 'openlayers__control__mouseposition.inc',
    ),
  );
}

/**
 * Class openlayers__control__mouseposition.
 */
class openlayers__control__mouseposition extends openlayers_control {

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
