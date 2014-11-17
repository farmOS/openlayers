<?php
/**
 * @file
 * Class openlayers_layers_ui.
 */

namespace Drupal\openlayers\UI;

/**
 * Class openlayers_layers_ui.
 */
class LayersUI extends \ObjectsUI {

  /**
   * {@inheritdoc}
   */
  public function edit_form_validate(&$form, &$form_state) {
    parent::edit_form_validate($form, $form_state);

    $layer = $form_state['values']['class'];
    $form_state['values']['options'] = $form_state['values']['options'][$layer];
    $form_state['values']['options']['source'] = $form_state['values']['source'];
    unset($form_state['values']['data']);
  }

  /**
   * {@inheritdoc}
   */
  public function hook_menu(&$items) {
    parent::hook_menu($items);
    $items['admin/structure/openlayers/layers']['type'] = MENU_LOCAL_TASK;
    $items['admin/structure/openlayers/layers']['weight'] = -5;
  }

}
