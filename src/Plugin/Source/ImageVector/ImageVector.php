<?php
/**
 * @file
 * Source: ImageVector.
 */

namespace Drupal\openlayers\Source;
use Drupal\openlayers\Source;

/**
 * Class ImageVector.
 */
class ImageVector extends Source {

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
  }
}
