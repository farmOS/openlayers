<?php
/**
 * @file
 * Interaction: DragFeature.
 */

namespace Drupal\openlayers_library\Plugin\Interaction\DragFeature;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Interaction;

/**
 * Class DragFeature.
 *
 * @OpenlayersPlugin(
 *  id = "DragFeature",
 *  description = "You can drag features around on the map."
 * )
 */
class DragFeature extends Interaction {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['style'] = array(
      '#type' => 'select',
      '#title' => t('Style when drag'),
      '#empty_option' => t('- Select the Style -'),
      '#default_value' => $this->getOption('style', array()),
      '#description' => t('Select the style.'),
      '#options' => Openlayers::loadAllAsOptions('Style'),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function optionsToObjects() {
    $import = parent::optionsToObjects();

    if ($style = $this->getOption('style', FALSE)) {
      $style = Openlayers::load('style', $style);

      // This source is a dependency of the current one,
      // we need a lighter weight.
      $this->setWeight($style->getWeight() + 1);
      $import = array_merge($style->getCollection()
        ->getFlatList(), $import);
    }

    return $import;
  }

}
