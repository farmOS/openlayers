<?php
/**
 * @file
 * Source: OSM.
 */

namespace Drupal\openlayers\source;
use Drupal\openlayers\Source;

/**
 * Class openlayers__source__osm.
 */
class osm extends Source {

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    $form['options']['url'] = array(
      '#type' => 'textarea',
      '#title' => t('Base URL (template)'),
      '#default_value' => $this->getOption('url') ? implode("\n", (array) $this->getOption('url')) : 'http://a.tile.openstreetmap.org/${z}/${x}/${y}.png',
      '#maxlength' => 2083,
    );
  }

  /**
   * {@inheritdoc}
   */
  public function options_form_submit($form, &$form_state) {
    if ($form_state['values']['options']['url'] == '') {
      unset($form_state['item']->options['url']);
    }
  }
}
