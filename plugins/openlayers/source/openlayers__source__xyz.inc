<?php
/**
 * @file
 * Source: XYZ.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__source__xyz_openlayers_source() {
  return array(
    'handler' => array(
      'class' => 'openlayers__source__xyz',
      'file' => 'openlayers__source__xyz.inc',
    ),
  );
}

/**
 * Class openlayers__source__xyz.
 */
class openlayers__source__xyz extends openlayers_source {
  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    $form['options']['url'] = array(
      '#title' => t('URL(s)'),
      '#type' => 'textarea',
      '#default_value' => $this->getOption('url') ? $this->getOption('url') : '',
    );
  }
}
