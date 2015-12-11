<?php
/**
 * @file
 * Default maps from views.
 */

/**
 * Implements hook_default_openlayers_maps_alter().
 */
function openlayers_views_default_openlayers_maps_alter(&$maps) {
  foreach (openalyers_views_get_views('openlayers_map_views') as $data) {
    list($view, $display) = $data;
    $view->set_display($display);
    $options = $view->display_handler->get_option('style_options');

    /** @var $basemap StdClass */
    $basemap = \Drupal\openlayers\Openlayers::loadExportable('map', $options['basemap']);
    $map = clone $basemap;

    $machine_name = 'map_views_' . $view->name . '_' . $display;
    $map->machine_name = $machine_name;
    $map->name = 'Views Map: ' . $view->name . ':' . $display;
    $map->description = t('Map from !link views map', array('!link' => l(t('this'), 'admin/structure/views/view/' . $view->name . '/edit/' . $display)));
    $map->factory_service = 'openlayers.Map:OLMap';
    $map->options += array(
      'views_display' => $view->name . ':' . $display,
    );
    $map->options['layers'][] = 'layer_map_views_' . $view->name . '_' . $display;

    $maps[$machine_name] = $map;
  }
}
