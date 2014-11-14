<?php
/**
 * @file
 * Source: BingMaps.
 */

namespace Drupal\openlayers\source;
use Drupal\openlayers\Source;

/**
 * Class openlayers__source__bingmaps.
 */
class bingmaps extends Source {

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    $layer_types = array(
      'Road',
      'Aerial',
      'AerialWithLabels',
      'collinsBart',
      'ordnanceSurvey',
    );

    $form['options']['key'] = array(
      '#title' => t('Key'),
      '#type' => 'textfield',
      '#default_value' => $this->getOption('key', ''),
    );
    $form['options']['imagerySet'] = array(
      '#title' => t('Imagery set'),
      '#type' => 'select',
      '#default_value' => $this->getOption('imagerySet', 'Road'),
      '#options' => array_combine($layer_types, $layer_types),
    );
  }

}
