<?php
/**
 * @file
 * Source: Stamen.
 */

namespace Drupal\openlayers\source;
use Drupal\openlayers\Source;

class stamen extends Source {

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    $form['options']['layer'] = array(
      '#title' => t('Source type'),
      '#type' => 'select',
      '#default_value' => $this->getOption('layer', 'osm'),
      '#options' => array(
        'terrain-labels' => 'Terrain labels',
        'watercolor' => 'Watercolor',
      ),
    );
  }

}
