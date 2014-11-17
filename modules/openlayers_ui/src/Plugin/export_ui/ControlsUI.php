<?php

namespace Drupal\openlayers\UI;

class ControlsUI extends \ObjectsUI {

  /**
   * Entry point of hook_menu().
   *
   * Child implementations that need to add or modify menu items should
   * probably call parent::hook_menu($items) and then modify as needed.
   */
  function hook_menu(&$items) {
    parent::hook_menu($items);
    $items['admin/structure/openlayers/controls']['type'] = MENU_LOCAL_TASK;
    $items['admin/structure/openlayers/controls']['weight'] = 1;
  }

}
