<?php
/**
 * @file
 * Class openlayers_config.
 */

namespace Drupal\openlayers;

/**
 * Class openlayers_config.
 */
class Config {
  const JS_GROUP = 'openlayers';
  const JS_WEIGHT = 10;
  const EDIT_VIEW_MAP = 'openlayers_map_view_edit_form';
  const WATCHDOG_TYPE = 'openlayers';
  // Set this to null to load the 'non-debug' library.
  const LIBRARY_VARIANT = 'debug';
}
