<?php
/**
 * @file
 * Contains \Drupal\openlayers\Plugin\PluginInterface;
 */

namespace Drupal\openlayers\Plugin;

/**
 * Defines an interface for openlayers plugin objects.
 *
 * @ingroup rendercache
 */
interface PluginInterface {
  /**
   * Public constructor.
   *
   * @param array $plugin
   *   The plugin associated with this class.
   */
  public function __construct($plugin);

  /**
   * Returns the plugin associated with this class.
   *
   * @return array
   *   The plugin array from the plugin class's associated .inc file.
   */
  public function getPlugin();

  /**
   * Returns the type this plugin implements.
   *
   * @return string
   *   The type this plugin implements.
   */
  public function getType();
}
