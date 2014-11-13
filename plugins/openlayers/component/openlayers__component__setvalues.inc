<?php
/**
 * @file
 * Component: SetValues.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__component__setvalues_openlayers_component() {
  return array(
    'handler' => array(
      'class' => 'openlayers__component__setvalues',
      'file' => 'openlayers__component__setvalues.inc',
    ),
  );
}

/**
 * Class openlayers__component__setvalues.
 */
class openlayers__component__setvalues extends openlayers_component {
  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    $form['options']['latitude'] = array(
      '#type' => 'textfield',
      '#title' => t('Latitude'),
      '#default_value' => $this->getOption('latitude'),
    );
    $form['options']['longitude'] = array(
      '#type' => 'textfield',
      '#title' => t('Longitude'),
      '#default_value' => $this->getOption('longitude'),
    );
    $form['options']['rotation'] = array(
      '#type' => 'textfield',
      '#title' => t('Rotation'),
      '#default_value' => $this->getOption('rotation'),
    );
    $form['options']['zoom'] = array(
      '#type' => 'textfield',
      '#title' => t('Zoom'),
      '#default_value' => $this->getOption('zoom'),
    );
  }

}
