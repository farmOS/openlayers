<?php

/**
 * @file
 * Contains \Drupal\openlayers\DependencyInjection\ContainerAware
 */

namespace Drupal\openlayers\DependencyInjection;

/**
 * ContainerAware is a simple implementation of ContainerAwareInterface.
 *
 * @ingroup dic
 */
abstract class ContainerAware implements ContainerAwareInterface {
  /**
   * The injected container.
   *
   * @var ContainerInterface
   */
  protected $container;

  /**
   * {@inheritdoc}
   */
  public function setContainer(ContainerInterface $container = null) {
    $this->container = $container;
  }
}
