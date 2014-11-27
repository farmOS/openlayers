<?php
/**
 * @file
 * Component: Block Layer Switcher.
 */

namespace Drupal\openlayers\Component;
use Drupal\openlayers\Types\Component;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Component\\BlockLayerSwitcher',
);

/**
 * Class BlockLayerSwitcher.
 */
class BlockLayerSwitcher extends Component {

  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, \Drupal\openlayers\Types\ObjectInterface $context = NULL) {
    $build['component'] = array(
      '#type' => 'fieldset',
      '#title' => 'Layer Switcher',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $build['component']['block'] = drupal_get_form('olebs_blockswitcher_form', $context);

    $build['map']['#attributes']['style'] = $build['#attributes']['style'];
    unset($build['#attributes']['style']);
  }

}
