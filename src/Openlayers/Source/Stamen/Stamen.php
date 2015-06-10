<?php
/**
 * @file
 * Source: Stamen.
 */

namespace Drupal\openlayers\Source;
use Drupal\openlayers\Types\Source;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Source\\Stamen',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

class Stamen extends Source {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
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
