<?php
/**
 * @file
 * Source: Cluster.
 */

/**
 * Plugin definition.
 */
function openlayers_cluster_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\cluster',
    ),
  );
}
