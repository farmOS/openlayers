<?php
/**
 * @file
 * Control: Attribution.
 */

namespace Drupal\openlayers\Plugin\Control\Attribution;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Control;

/**
 * Class Attribution.
 *
 * @OpenlayersPlugin(
 *  id = "Attribution"
 * )
 *
 */
class Attribution extends Control {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['collapsible'] = array(
      '#type' => 'checkbox',
      '#title' => t('Collapsible'),
      '#default_value' => $this->getOption('collapsible'),
    );
  }

}
