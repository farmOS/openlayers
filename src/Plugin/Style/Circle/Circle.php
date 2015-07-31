<?php
/**
 * @file
 * Style: Circle.
 */

namespace Drupal\openlayers\Plugin\Style\Circle;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Style;

/**
 * Class Circle.
 *
 * @OpenlayersPlugin(
 *  id = "Circle"
 * )
 */
class Circle extends Style {
  /**
   * @inheritDoc
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['radius'] = array(
      '#type' => 'textfield',
      '#title' => 'Radius',
      '#default_value' => $this->getOption('radius', '5'),
    );
    $form['options']['fill']['color'] = array(
      '#type' => 'textfield',
      '#title' => 'Fill color',
      '#field_prefix' => 'rgba(',
      '#field_suffix' => ')',
      '#default_value' => $this->getOption(array('fill', 'color'), '255,255,255,0.4'),
    );
    $form['options']['stroke'] = array(
      '#type' => 'fieldset',
      '#title' => 'Stroke',
    );
    $form['options']['stroke']['color'] = array(
      '#type' => 'textfield',
      '#title' => 'Color',
      '#field_prefix' => 'rgba(',
      '#field_suffix' => ')',
      '#default_value' => $this->getOption(array('stroke', 'color'), '51,153,204,1'),
    );
    $form['options']['stroke']['width'] = array(
      '#type' => 'textfield',
      '#title' => 'Width',
      '#default_value' => $this->getOption(array('stroke', 'width'), 1.25),
    );
  }
}
