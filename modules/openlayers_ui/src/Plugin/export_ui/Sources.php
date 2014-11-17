<?php
/**
 * @file
 * Class openlayers_components_ui.
 */

namespace Drupal\openlayers\UI;

/**
 * Class openlayers_components_ui.
 */
class Sources extends \ObjectsUI {

  /**
   * {@inheritdoc}
   */
  public function hook_menu(&$items) {
    parent::hook_menu($items);
    $items['admin/structure/openlayers/sources']['type'] = MENU_LOCAL_TASK;
    $items['admin/structure/openlayers/sources']['weight'] = -1;
  }

}
