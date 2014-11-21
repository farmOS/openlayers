<?php

/**
 * @file
 * Contains \Drupal\openlayers\DependencyInjection\ContainerAwareInterface
 */

namespace Drupal\openlayers\DependencyInjection;

/**
 * ContainerAwareInterface should be implemented by classes that depend on a Container.
 *
 * @ingroup dic
 */
interface ContainerAwareInterface {

  /**
   * Sets the Container associated with this service.
   *
   * @param ContainerInterface|null $container
   *   A ContainerInterface instance or NULL to be injected in the service.
   */
  public function setContainer(ContainerInterface $container = NULL);
}
