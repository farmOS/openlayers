<?php
/**
 * @file
 * Component: SetValues.
 */

namespace Drupal\openlayers\Component;
use Drupal\openlayers\Component;

/**
 * Class SetValues.
 */
class SetValues extends Component {
  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    $form['options']['latitude'] = array(
      '#type' => 'textfield',
      '#title' => t('Latitude'),
      '#default_value' => $this->getOption('latitude'),
    );
    $form['options']['longitude'] = array(
      '#type' => 'textfield',
      '#title' => t('Longitude'),
      '#default_value' => $this->getOption('longitude'),
    );
    $form['options']['rotation'] = array(
      '#type' => 'textfield',
      '#title' => t('Rotation'),
      '#default_value' => $this->getOption('rotation'),
    );
    $form['options']['zoom'] = array(
      '#type' => 'textfield',
      '#title' => t('Zoom'),
      '#default_value' => $this->getOption('zoom'),
    );
  }

}
