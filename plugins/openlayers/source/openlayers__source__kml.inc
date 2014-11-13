<?php
/**
 * @file
 * Source: KML.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__source__kml_openlayers_source() {
  return array(
    'handler' => array(
      'class' => 'openlayers__source__kml',
      'file' => 'openlayers__source__kml.inc',
    ),
  );
}

/**
 * Class openlayers__source__kml.
 */
class openlayers__source__kml extends openlayers_source {

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    $form['options']['url'] = array(
      '#title' => t('URL'),
      '#type' => 'textfield',
      '#default_value' => $this->getOption('url'),
    );
  }
}
