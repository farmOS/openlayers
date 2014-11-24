<?php

function _openlayers_services_retrieve($name) {
  $map = openlayers_object_load('map', check_plain($name));
  $build = $map->build();
  $render = drupal_render($build);
  $js = drupal_get_js();
  $styles = drupal_get_css();

  return theme('openlayers_iframe', array('page'=>$render, 'scripts' => $js, 'styles' => $styles));
}

function _openlayers_services_access() {
  return TRUE;
}
