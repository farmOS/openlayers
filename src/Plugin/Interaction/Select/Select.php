<?php
/**
 * @file
 * Interaction: Select.
 */

namespace Drupal\openlayers\Plugin\Interaction\Select;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Interaction;

/**
 * Class Select.
 *
 * @OpenlayersPlugin(
 *  id = "Select",
 *  description = "Handles selection of vector data."
 * )
 */
class Select extends Interaction {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['condition'] = array(
      '#type' => 'select',
      '#title' => t('Condition'),
      '#empty_option' => t('- Select a condition -'),
      '#default_value' => $this->getOption('condition', 'singleClick'),
      '#description' => t('Select the condition.'),
      '#options' => array(
        'singleClick' => t('Single click'),
        'shiftKeyOnly' => t('Shift key only'),
        'pointerMove' => t('Pointer move'),
      ),
      '#required' => TRUE,
    );
    $form['options']['style'] = array(
      '#type' => 'select',
      '#title' => t('Style'),
      '#empty_option' => t('- Select a Style -'),
      '#default_value' => $this->getOption('style', ''),
      '#description' => t('Select the source.'),
      '#options' => Openlayers::loadAllAsOptions('Style'),
      '#required' => TRUE,
    );
  }

  /**
   * {@inheritDoc}
   */
  public function optionsToObjects() {
    $import = parent::optionsToObjects();

    if ($style = $this->getOption('style')) {
      $style = Openlayers::load('style', $style);

      // This style is a dependency of the current one,
      // we need a lighter weight.
      $this->setWeight($style->getWeight() + 1);
      $import = array_merge($style->getCollection()->getFlatList(), $import);
    }

    return $import;
  }

}
