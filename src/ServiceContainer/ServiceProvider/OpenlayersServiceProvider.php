<?php
/**
 * @file
 * Contains \Drupal\openlayers\RenderCache\ServiceProvider\RenderCacheServiceProvider
 */

namespace Drupal\openlayers\ServiceContainer\ServiceProvider;

use Drupal\service_container\ServiceContainer\ServiceProvider\ServiceContainerServiceProvider;

/**
 * Provides openlayers service definitions.
 */
class OpenlayersServiceProvider extends ServiceContainerServiceProvider {

  /**
   * {@inheritdoc}
   */
  public function getContainerDefinition() {
    $services = array();
    $parameters = array();

    $services['service_container'] = array(
      'class' => '\Drupal\service_container\DependencyInjection\Container',
    );

    $services['openlayers.error'] = array(
      'class' => '\Drupal\openlayers\Types\Error',
    );

    $services['openlayers.collection'] = array(
      'class' => '\Drupal\openlayers\Types\Collection',
    );

    // Plugin Managers - filled out by alterDefinition() of service_container
    // module.
    // This needs to exist in an empty state.
    $services['openlayers.map'] = array();
    $services['openlayers.layer'] = array();
    $services['openlayers.source'] = array();
    $services['openlayers.control'] = array();
    $services['openlayers.interaction'] = array();
    $services['openlayers.style'] = array();
    $services['openlayers.component'] = array();

    // Syntax is: <service_name> => <plugin_manager_definition>
    $parameters['service_container.plugin_managers']['ctools'] = array(
      'openlayers.map' => array(
        'owner' => 'openlayers',
        'type' => 'Map',
      ),
      'openlayers.layer' => array(
        'owner' => 'openlayers',
        'type' => 'Layer',
      ),
      'openlayers.source' => array(
        'owner' => 'openlayers',
        'type' => 'Source',
      ),
      'openlayers.control' => array(
        'owner' => 'openlayers',
        'type' => 'Control',
      ),
      'openlayers.interaction' => array(
        'owner' => 'openlayers',
        'type' => 'Interaction',
      ),
      'openlayers.style' => array(
        'owner' => 'openlayers',
        'type' => 'Style',
      ),
      'openlayers.component' => array(
        'owner' => 'openlayers',
        'type' => 'Component',
      ),
    );

    return array(
      'parameters' => $parameters,
      'services' => $services,
    );
  }
}
