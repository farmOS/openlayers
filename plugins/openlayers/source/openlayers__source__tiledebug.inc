<?php
/**
 * @file
 * Source: TileDebug.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__source__tiledebug_openlayers_source() {
  return array(
    'handler' => array(
      'class' => 'openlayers__source__tiledebug',
      'file' => 'openlayers__source__tiledebug.inc',
    ),
  );
}

/**
 * Class openlayers__source__tiledebug.
 */
class openlayers__source__tiledebug extends openlayers_source {

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    $form['options']['maxZoom'] = array(
      '#title' => t('Maxzoom'),
      '#type' => 'textfield',
      '#default_value' => $this->getOption('maxZoom', 22),
    );
  }

}
