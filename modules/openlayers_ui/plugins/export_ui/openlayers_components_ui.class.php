<?php
/**
 * @file
 * Class openlayers_components_ui.
 */

/**
 * Class openlayers_components_ui.
 */
class openlayers_components_ui extends openlayers_objects_ui {

  /**
   * {@inheritdoc}
   */
  public function hook_menu(&$items) {
    parent::hook_menu($items);
    $items['admin/structure/openlayers/components']['type'] = MENU_LOCAL_TASK;
    $items['admin/structure/openlayers/components']['weight'] = 3;
  }

}
