<?php
/**
 * @file
 * Source: Mapquest.
 */

namespace Drupal\openlayers\source;
use Drupal\openlayers\Source;

/**
 * Class openlayers__source__mapquest.
 */
class mapquest extends Source {

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    $layer_types = array(
      'osm' => 'OpenStreetMap',
      'sat' => 'Satellite',
      'hyb' => 'Hybrid',
    );

    $form['options']['layer'] = array(
      '#title' => t('Source type'),
      '#type' => 'select',
      '#default_value' => $this->getOption('layer', 'osm'),
      '#options' => $layer_types,
    );
  }

}
