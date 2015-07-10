<?php
/**
 * @file
 * Source: Cluster.
 */

namespace Drupal\openlayers\Plugin\Source\Cluster;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Source;

/**
 * Class Cluster.
 *
 * @OpenlayersPlugin(
 *  id = "Cluster"
 * )
 *
 */
class Cluster extends Source {
  /**
   * {@inheritdoc}
   */
  public function init() {
    parent::init();
    if ($source = $this->getOption('source')) {
      $object = Openlayers::load('source', $source);
      $this->getCollection()->merge($object->getCollection());
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getOptions() {
    $options = parent::getOptions();

    if ($sources = $this->getObjects('source')) {
      $source = array_shift($sources);
      $options['source'] = $source->machine_name;
    }

    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['source'] = array(
      '#type' => 'select',
      '#title' => t('Source'),
      '#empty_option' => t('- Select a Source -'),
      '#default_value' => isset($form_state['item']->options['source']) ? $form_state['item']->options['source'] : '',
      '#description' => t('Select the source.'),
      '#options' => \Drupal\openlayers\Openlayers::loadAllAsOptions('Source'),
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
