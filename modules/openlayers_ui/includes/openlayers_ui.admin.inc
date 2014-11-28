<?php
/**
 * @file
 * This file holds the functions for the main openlayers Admin settings.
 *
 * @ingroup openlayers
 */

/**
 * Menu callback; displays the openlayers module settings page.
 *
 * @see system_settings_form()
 */
function openlayers_ui_admin_settings($form, &$form_state) {
  ctools_include('plugins');
  ctools_include('export');
  $maps = ctools_export_crud_load_all('openlayers_maps');
  $options = array();
  foreach ($maps as $machine_name => $data) {
    // Todo: Rewrite properly and create a generic function to load all objects.
    if (property_exists($data, 'disabled') && ($data->disabled == 1 || $data->disabled == TRUE)) {
      continue;
    }
    $options[$data->machine_name] = $data->name;
  }

  $map = 'openlayers_map_ui_default';
  if (isset($form_state['values']['openlayers_default_map'])) {
    $map = $form_state['values']['openlayers_default_map'];
  }

  $form['openlayers_default_map'] = array(
    '#type' => 'select',
    '#title' => t('OpenLayers maps'),
    '#description' => t('This form is just a test, it just shows the AJAX possibility of the module.'),
    '#options' => $options,
    '#default_value' => $map,
    '#ajax' => array(
      'callback' => '_ajax_reload_default_map',
      'method' => 'replace',
      'wrapper' => 'default_map_ajax',
      'effect' => 'fade',
    ),
  );

  $form['default_map'] = array(
    '#prefix' => '<div id="default_map_ajax">',
    '#suffix' => '</div>',
    '#type' => 'openlayers',
    '#map' => $map,
  );

  // This is for preventing 'system/ajax' as destination when using AJAX maps.
  // See: http://drupal.stackexchange.com/questions/86958/get-current-url-arguments-inside-ajax-callback
  $form['current_path'] = array('#type' => 'hidden', '#value' => current_path());

  // Make a system setting form and return.
  return system_settings_form($form);
}

/**
 * @TODO: Document.
 */
function _ajax_reload_default_map($form, &$form_state) {
  // This is for preventing 'system/ajax' as destination when using AJAX maps.
  // See: http://drupal.stackexchange.com/questions/86958/get-current-url-arguments-inside-ajax-callback
  $_SESSION['current_path'] = $form_state['input']['current_path'];
  return $form['default_map'];
}
