<?php
/**
 * @file
 * Component: Block Layer Switcher.
 */

namespace Drupal\openlayers\component;
use Drupal\openlayers\Component;

/**
 * Class openlayers_examples__component__blocklayerswitcher.
 */
class blocklayerswitcher extends Component {

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
