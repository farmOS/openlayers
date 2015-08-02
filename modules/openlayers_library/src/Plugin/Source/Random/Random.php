<?php
/**
 * @file
 * Source: Random.
 */

namespace Drupal\openlayers_library\Plugin\Source\Random;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Source;

/**
 * Class Random.
 *
 * @OpenlayersPlugin(
 *  id = "Random"
 * )
 */
class Random extends Source {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['count'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of features'),
      '#default_value' => $this->getOption('count', 250),
      '#required' => TRUE,
    );
    $form['options']['setRandomStyle'] = array(
      '#type' => 'checkbox',
      '#title' => t('Set random style on features ?'),
      '#default_value' => $this->getOption('setRandomStyle', 0),
    );
    $form['options']['style'] = array(
      '#type' => 'select',
      '#title' => t('Styles'),
      '#empty_option' => t('- Select the Styles -'),
      '#default_value' => $this->getOption('style', array()),
      '#description' => t('Select the styles.'),
      '#options' => Openlayers::loadAllAsOptions('Style'),
      '#required' => TRUE,
      '#multiple' => TRUE,
      '#states' => array(
        'visible' => array(
          'input[name="options[setRandomStyle]"' => array('checked' => TRUE),
        ),
      ),
    );
  }

  /**
   * {@inheritDoc}
   */
  public function optionsToObjects() {
    $import = parent::optionsToObjects();

    if ($styles = $this->getOption('style', array())) {
      foreach($styles as $style) {
        $style = Openlayers::load('style', $style);

        // This source is a dependency of the current one,
        // we need a lighter weight.
        $this->setWeight($style->getWeight() + 1);
        $import = array_merge($style->getCollection()->getFlatList(), $import);
      }
    }

    return $import;
  }
}
