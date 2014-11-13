<?php
/**
 * @file
 * Source: TileJson.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__source__tilejson_openlayers_source() {
  return array(
    'handler' => array(
      'class' => 'openlayers__source__tilejson',
      'file' => 'openlayers__source__tilejson.inc',
    ),
  );
}

/**
 * Class openlayers__source__tilejson.
 */
class openlayers__source__tilejson extends openlayers_source {

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
