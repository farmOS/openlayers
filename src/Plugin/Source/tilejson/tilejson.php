<?php
/**
 * @file
 * Source: TileJson.
 */

namespace Drupal\openlayers\Source;
use Drupal\openlayers\Source;

/**
 * Class openlayers__source__tilejson.
 */
class tilejson extends Source {

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
