<?php
// $Id$

/**
 * @file
 * OpenLayers default packaged behaviors
 */

/**
 * Implementation of hook_openlayers_behaviors().
 *
 */
function _openlayers_openlayers_behaviors() {
  return array(
    'openlayers_behavior_attribution' => array(
       'title' => t('Attribution'),
       'description' => t('Allows layers to provide attribution to the map if it exists.'),
       'type' => 'layer',
       'path' => drupal_get_path('module', 'openlayers') .'/includes/behaviors',
       'file' => 'openlayers_behavior_attribution.inc',
       'behavior' => array(
         'class' => 'openlayers_behavior_attribution',
         'parent' => 'openlayers_behavior',
       ),
     ),
    'openlayers_behavior_keyboarddefaults' => array(
       'title' => t('Keyboard Defaults'),
       'description' => t('Provides a the ability to use the keyboard to pan and zoom map.'),
       'type' => 'layer',
       'path' => drupal_get_path('module', 'openlayers') .'/includes/behaviors',
       'file' => 'openlayers_behavior_keyboarddefaults.inc',
       'behavior' => array(
         'class' => 'openlayers_behavior_keyboarddefaults',
         'parent' => 'openlayers_behavior',
       ),
     ),
    'openlayers_behavior_layerswitcher' => array(
       'title' => t('Layer Switcher'),
       'description' => t('Gives user ability to switch Layers in the map interface.'),
       'type' => 'map',
       'path' => drupal_get_path('module', 'openlayers') .'/includes/behaviors',
       'file' => 'openlayers_behavior_layerswitcher.inc',
       'behavior' => array(
         'class' => 'openlayers_behavior_layerswitcher',
         'parent' => 'openlayers_behavior',
       ),
     ),
    'openlayers_behavior_mouseposition' => array(
       'title' => t('Mouse Position'),
       'description' => t('Gives a visual indication of the mouse position to the user.'),
       'type' => 'map',
       'path' => drupal_get_path('module', 'openlayers') .'/includes/behaviors',
       'file' => 'openlayers_behavior_mouseposition.inc',
       'behavior' => array(
         'class' => 'openlayers_behavior_mouseposition',
         'parent' => 'openlayers_behavior',
       ),
     ),
    'openlayers_behavior_navigation' => array(
       'title' => t('Navigation'),
       'description' => t('Gives the user the ability to navigate the map interface.'),
       'type' => 'map',
       'path' => drupal_get_path('module', 'openlayers') .'/includes/behaviors',
       'file' => 'openlayers_behavior_navigation.inc',
       'behavior' => array(
         'class' => 'openlayers_behavior_navigation',
         'parent' => 'openlayers_behavior',
       ),
     ),
     'openlayers_behavior_dragpan' => array(
      'title' => t('DragPan'),
      'description' => t('Gives user ability to pan in the map interface.'),
      'type' => 'map',
      'path' => drupal_get_path('module', 'openlayers') .'/includes/behaviors',
      'file' => 'openlayers_behavior_dragpan.inc',
      'behavior' => array(
        'class' => 'openlayers_behavior_dragpan',
        'parent' => 'openlayers_behavior',
      ),
    ),
    'openlayers_behavior_panzoom' => array(
      'title' => t('PanZoom'),
      'description' => t('Gives user ability to pan and zoom in the map interface.'),
      'type' => 'map',
      'path' => drupal_get_path('module', 'openlayers') .'/includes/behaviors',
      'file' => 'openlayers_behavior_panzoom.inc',
      'behavior' => array(
        'class' => 'openlayers_behavior_panzoom',
        'parent' => 'openlayers_behavior',
      ),
    ),
    'openlayers_behavior_panzoombar' => array(
      'title' => t('PanZoomBar'),
      'description' => t('Gives user ability to pan and zoom, with a zoom bar, in the map interface.'),
      'type' => 'map',
      'path' => drupal_get_path('module', 'openlayers') .'/includes/behaviors',
      'file' => 'openlayers_behavior_panzoombar.inc',
      'behavior' => array(
        'class' => 'openlayers_behavior_panzoombar',
        'parent' => 'openlayers_behavior',
      ),
    ),
    'openlayers_behavior_mapformvalues' => array(
      'title' => t('Map Form Values'),
      'description' => t('Private method for admin UI'),
      'type' => 'map',
      'path' => drupal_get_path('module', 'openlayers') .'/includes/behaviors',
      'file' => 'openlayers_behavior_mapformvalues.inc',
      'behavior' => array(
        'class' => 'openlayers_behavior_mapformvalues',
        'parent' => 'openlayers_behavior',
      ),
    ),
    'openlayers_behavior_boxselect' => array(
      'title' => t('Boxselect'),
      'description' => t('Allows the selection and display of a box.'),
      'type' => 'map',
      'path' => drupal_get_path('module', 'openlayers') .'/includes/behaviors',
      'file' => 'openlayers_behavior_boxselect.inc',
      'behavior' => array(
        'class' => 'openlayers_behavior_boxselect',
        'parent' => 'openlayers_behavior',
      ),
    ),
    'openlayers_behavior_permalink' => array(
      'title' => t('Permalink'),
      'description' =>  t('Provides a URL that will link to a specific map position.'),
      'type' => 'map',
      'path' => drupal_get_path('module', 'openlayers') .'/includes/behaviors',
      'file' => 'openlayers_behavior_permalink.inc',
      'behavior' => array(
        'class' => 'openlayers_behavior_permalink',
        'parent' => 'openlayers_behavior',
      ),
    ),
    'openlayers_behavior_scaleline' => array(
      'title' => t('Scale Line'),
      'description' => t('Provides the user with a line of scale in the map interface.'),
      'type' => 'map',
      'path' => drupal_get_path('module', 'openlayers') .'/includes/behaviors',
      'file' => 'openlayers_behavior_scaleline.inc',
      'behavior' => array(
        'class' => 'openlayers_behavior_scaleline',
        'parent' => 'openlayers_behavior',
      ),
    ),
    'openlayers_behavior_zoombox' => array(
      'title' => t('Zoom Box'),
      'description' => t('Allows user to draw a box on screen to zoom with Shift + Click.'),
      'type' => 'map',
      'path' => drupal_get_path('module', 'openlayers') .'/includes/behaviors',
      'file' => 'openlayers_behavior_zoombox.inc',
      'behavior' => array(
        'class' => 'openlayers_behavior_zoombox',
        'parent' => 'openlayers_behavior',
      ),
    ),
    'openlayers_behavior_zoomtomaxextent' => array(
      'title' => t('Zoom to Max Extent'),
      'description' => t('Provides button to zoom to the maximum extent of the map.'),
      'type' => 'map',
      'path' => drupal_get_path('module', 'openlayers') .'/includes/behaviors',
      'file' => 'openlayers_behavior_zoomtomaxextent.inc',
      'behavior' => array(
        'class' => 'openlayers_behavior_zoomtomaxextent',
        'parent' => 'openlayers_behavior',
      ),
    ),
  );
}