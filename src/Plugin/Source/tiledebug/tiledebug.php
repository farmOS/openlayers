<?php
/**
 * @file
 * Source: TileDebug.
 */

namespace Drupal\openlayers\Source;
use Drupal\openlayers\Source;

/**
 * Class openlayers__source__tiledebug.
 */
class tiledebug extends Source {

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
