<?php
/**
 * @file
 * Component: Bootstap JS Popup.
 */

namespace Drupal\openlayers\Component;
use Drupal\openlayers\Component;

/**
 * Class openlayers__component__bootstrapjs_popup.
 */
class bootstrapjsPopup extends Component {

  /**
   * {@inheritdoc}
   */
  public function attached(\Drupal\openlayers\ObjectInterface $context) {
    $attached = parent::attached($context);
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
