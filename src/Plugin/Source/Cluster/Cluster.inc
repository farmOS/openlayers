<?php
/**
 * @file
 * Source: Cluster.
 */

/**
 * Plugin definition.
 */
function openlayers_Cluster_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\Cluster',
    ),
  );
}
