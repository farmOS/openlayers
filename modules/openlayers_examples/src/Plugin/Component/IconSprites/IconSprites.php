<?php
/**
 * @file
 * Component: IconSprites.
 */

namespace Drupal\openlayers_examples\Plugin\Component\IconSprites;
use Drupal\Component\Annotation\Plugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Component;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class IconSprites.
 *
 * @Plugin(
 *   id = "IconSprites"
 * )
 *
 */
class IconSprites extends Component {
  /**
   * {@inheritdoc}
   */
  public function getJS() {
    $js = parent::getJS();
    $js['opt']['url'] = file_create_url(drupal_get_path('module', 'openlayers_examples') . '/assets/Butterfly.png');

    return $js;
  }
}
