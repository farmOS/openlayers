<?php
/**
 * @file
 * Component: Block Layer Switcher.
 */

namespace Drupal\openlayers\Component;
use Drupal\openlayers\Component;

/**
 * Class BlockLayerSwitcher.
 */
class BlockLayerSwitcher extends Component {

  /**
   * {@inheritdoc}
   */
  public function alterBuild(&$build, $map) {
    $build['component'] = array(
      '#type' => 'fieldset',
      '#title' => 'Layer Switcher',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $build['component']['block'] = drupal_get_form('olebs_blockswitcher_form', $map);

    $build['map']['#attributes']['style'] = $build['#attributes']['style'];
    unset($build['#attributes']['style']);
  }

}
