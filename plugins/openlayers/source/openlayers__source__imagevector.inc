<?php
/**
 * @file
 * Source: ImageVector.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__source__imagevector_openlayers_source() {
  return array(
    'handler' => array(
      'class' => 'openlayers__source__imagevector',
      'file' => 'openlayers__source__imagevector.inc',
    ),
  );
}

/**
 * Class openlayers__source__imagevector.
 */
class openlayers__source__imagevector extends openlayers_source {

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    $form['options']['source'] = array(
      '#type' => 'select',
      '#title' => t('Source'),
      '#default_value' => isset($form_state['item']->options['source']) ? $form_state['item']->options['source'] : '',
      '#description' => t('Select the source.'),
      '#options' => openlayers_source_options(),
      '#required' => TRUE,
    );
  }
}
