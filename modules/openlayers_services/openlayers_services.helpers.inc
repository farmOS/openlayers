<?php
/**
 * @file
 * Helper functions
 */

function _openlayers_services_retrieve($name) {
  $map = \Drupal\openlayers\Openlayers::load('Map', $name);
  $build = $map->build();
  $render = drupal_render($build);
  $js = drupal_get_js();
  $styles = drupal_get_css();

  return theme('openlayers_map_iframe', array(
    'page' => $render,
    'scripts' => $js,
    'styles' => $styles,
  ));
}

function _openlayers_services_access($operation, $map) {
  $map = \Drupal\openlayers\Openlayers::load('Map', $map[0]);
  return (bool) $map->getOption('provideIframe', FALSE);
}
