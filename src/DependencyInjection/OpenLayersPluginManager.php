<?php

namespace Drupal\openlayers\DependencyInjection;

use Drupal\service_container\DependencyInjection\ServiceProviderPluginManager;
use Drupal\service_container\Plugin\Discovery\CToolsPluginDiscovery;

class OpenLayersPluginManager extends ServiceProviderPluginManager {

  /**
   * Constructs a ServiceProviderPluginManager object.
   *
   * This uses ctools for discovery of service_container ServiceProvider objects.
   *
   * @codeCoverageIgnore
   */
  public function __construct() {
    $discovery = new CToolsPluginDiscovery('openlayers', 'ServiceProvider');
    parent::__construct($discovery);
  }

}
