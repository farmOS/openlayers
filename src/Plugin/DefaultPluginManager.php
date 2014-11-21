<?php
/**
 * @file
 * Contains \Drupal\openlayers\Plugin\DefaultPluginManager
 */

namespace Drupal\openlayers\Plugin;

use Drupal\openlayers\Plugin\PluginManagerBase;
use Drupal\Component\Plugin\Factory\DefaultFactory;
use Drupal\Component\Plugin\Discovery\DiscoveryInterface;

/**
 * Defines a plugin manager used for discovering generic plugins.
 */
class DefaultPluginManager extends PluginManagerBase {

  /**
   * Constructs a DefaultPluginManager object.
   *
   * @param DiscoveryInterface $discovery
   *   The discovery object used to find plugins.
   */
  public function __construct(DiscoveryInterface $discovery) {
    $this->discovery = $discovery;
    // Use a generic factory.
    $this->factory = new DefaultFactory($this->discovery);
  }
}
