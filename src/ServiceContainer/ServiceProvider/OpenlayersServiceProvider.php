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

    $services['openlayers'] = array(
      'class' => '\Drupal\service_container\Plugin\ContainerAwarePluginManager',
      'arguments' => array(
        'openlayers.internal.',
      ),
      'calls' => array(
        array(
          'setContainer',
          array(
            '@service_container',
          ),
        ),
      ),
    );

    $services['openlayers.internal.error'] = array(
      'class' => '\Drupal\openlayers\Types\Error',
      'arguments' => array('@logger.channel.default'),
    );

    $services['openlayers.internal.collection'] = array(
      'class' => '\Drupal\openlayers\Types\Collection',
    );

    $parameters['ctools_plugins_auto_discovery']['openlayers'] = TRUE;

    return array(
      'parameters' => $parameters,
      'services' => $services,
    );
  }
}
