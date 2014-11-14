<?php
/**
 * @file
 * Source: KML.
 */

namespace Drupal\openlayers\source;
use Drupal\openlayers\Source;

/**
 * Class openlayers__source__kml.
 */
class kml extends Source {

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
