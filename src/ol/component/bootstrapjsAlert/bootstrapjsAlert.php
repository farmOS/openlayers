<?php
/**
 * @file
 * Component: Bootstrap JS.
 */

namespace Drupal\openlayers\component;
use Drupal\openlayers\Component;

/**
 * Class openlayers__component__bootstrapjs_alert.
 */
class bootstrapjsAlert extends Component {

  /**
   * {@inheritdoc}
   */
  public function attached() {
    $attached = parent::attached();
    $attached['libraries_load'][] = array('bootstrapjs');
    return $attached;
  }

  /**
   * {@inheritdoc}
   */
  public function dependencies() {
    return array(
      'bootstrapjs',
    );
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    $form['options']['message'] = array(
      '#type' => 'textarea',
      '#title' => t('Text to display'),
      '#default_value' => $this->getOption('message'),
    );
  }

}
