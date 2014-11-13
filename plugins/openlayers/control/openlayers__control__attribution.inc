<?php
/**
 * @file
 * Control: Attribution.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__control__attribution_openlayers_control() {
  return array(
    'handler' => array(
      'class' => 'openlayers__control__attribution',
      'file' => 'openlayers__control__attribution.inc',
    ),
  );
}

/**
 * Class openlayers__control__attribution.
 */
class openlayers__control__attribution extends openlayers_control {

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
