<?php
/**
 * @file
 * Source: Cluster.
 */

namespace Drupal\openlayers\source;
use Drupal\openlayers\Source;

/**
 * Class openlayers__source__cluster
 */
class cluster extends Source {

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

    $form['options']['distance'] = array(
      '#type' => 'textfield',
      '#title' => t('Cluster distance'),
      '#default_value' => isset($form_state['item']->options['distance']) ? $form_state['item']->options['distance'] : 50,
      '#description' => t('Cluster distance.'),
    );
  }
}
