<?php
/**
 * @file
 * Contains \Drupal\openlayers\DependencyInjection\ServiceProviderPluginManager
 */

namespace Drupal\openlayers\DependencyInjection;

use Drupal\Component\Plugin\PluginManagerBase;
use Drupal\Component\Plugin\Factory\DefaultFactory;
use Drupal\Component\Plugin\Discovery\DiscoveryInterface;
use Drupal\openlayers\Plugin\Discovery\CToolsPluginDiscovery;
use Drupal\openlayers\Plugin\DefaultPluginManager;

/**
 * Defines a plugin manager used for discovering container service definitions.
 */
class ServiceProviderPluginManager extends DefaultPluginManager {

  /**
   * Constructs a ServiceProviderPluginManager object.
   *
   * This uses ctools for discovery of render_cache ServiceProvider objects.
   */
  public function __construct() {
    $discovery = new CToolsPluginDiscovery('openlayers', 'ServiceProvider');
    parent::__construct($discovery);
  }
}
