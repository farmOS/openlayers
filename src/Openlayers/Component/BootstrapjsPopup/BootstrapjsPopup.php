<?php
/**
 * @file
 * Component: Bootstap JS Popup.
 */

namespace Drupal\openlayers\Component;
use Drupal\openlayers\Types\Component;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Component\\BootstrapjsPopup',
  'arguments' => array('@module_handler', '@messenger', '@drupal7'),
);

/**
 * Class BootstrapjsPopup.
 */
class BootstrapjsPopup extends Component {

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

}
