<?php
/**
 * @file
 * Class openlayers_components_ui.
 */

namespace Drupal\openlayers\UI;

/**
 * Class openlayers_components_ui.
 */
class Maps extends \ObjectsUI {

  /**
   * {@inheritdoc}
   */
  public function hook_menu(&$items) {
    parent::hook_menu($items);
    $items['admin/structure/openlayers/maps']['type'] = MENU_LOCAL_TASK;
    $items['admin/structure/openlayers/maps']['context'] = MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE;
    $items['admin/structure/openlayers/maps']['weight'] = -10;
  }

  /**
   * {@inheritdoc}
   */
  public function delete_form_submit(&$form_state) {
    parent::delete_form_submit($form_state);
    $delta = _openlayers_get_block_id($form_state['item']->machine_name);

    db_delete('block')
      ->condition('module', 'openlayers')
      ->condition('delta', $delta)
      ->execute();
  }

}
