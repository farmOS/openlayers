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
  $options = array();

  $form['origin'] = array(
    '#type' => 'fieldset',
    '#title' => 'Library loading configuration',
  );

  $library = libraries_detect('openlayers3');
  $options_variants = array();
  foreach ($library['variants'] as $version => $variant) {
    list($optgroup) = explode(':', $version, 2);
    if (empty($optgroup)) {
      $optgroup = t('Other');
    }
    $optgroup = drupal_strtoupper($optgroup);
    $options_variants[$optgroup][$version] = (isset($variant['name'])) ? $variant['name'] : $version;
  }

  $form['origin']['variant'] = array(
    '#type' => 'select',
    '#title' => 'Select the origin and version',
    '#options' => $options_variants,
    '#default_value' => \Drupal\openlayers\Config::get('openlayers.variant'),
  );

  $form['origin']['debug'] = array(
    '#type' => 'checkbox',
    '#title' => 'Load javascript debug integration files ?',
    '#default_value' => \Drupal\openlayers\Config::get('openlayers.debug'),
  );

  $form['plugin-info'] = array(
    '#type' => 'fieldset',
    '#title' => 'Plugin information',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  foreach (\Drupal\openlayers\Openlayers::getPluginTypes() as $plugin_type) {
    $rows = array();

    $form['plugin-info'][$plugin_type . '-group'] = array(
      '#type' => 'fieldset',
      '#title' => $plugin_type,
      '#collapsed' => TRUE,
      '#collapsible' => TRUE,
    );

    foreach (\Drupal::service('openlayers.' . $plugin_type)->getDefinitions() as $service => $definition) {
      $definition += array('arguments' => array('NULL'));

      list($module, $type,, $id) = explode('.', $service);

      $configuration = array(
        'name' => $definition['id'],
        'machine_name' => $definition['id'],
        'factory_service' => $module . '.' . $type . ':' . $id,
      );

      $instance = \Drupal\openlayers\Openlayers::load($plugin_type, $configuration);
      $attached = $instance->attached();

      $sizes = array('js' => 0, 'css' => 0);
      foreach (array_keys($sizes) as $size_type) {
        foreach ($attached[$size_type] as $data) {
          if (isset($data['type']) && $data['type'] != 'external') {
            if (!is_array($data['data'])) {
              $sizes[$size_type] += filesize($data['data']);
            }
          }
        }
      }

      foreach (array('js', 'css') as $file_type) {
        if (count($attached[$file_type]) != 0) {
          $sizes[$file_type] .= ' bytes.<br/>(' . count($attached[$file_type]);
          if (count($attached[$file_type]) == 1) {
            $sizes[$file_type] .= ' file)';
          }
          else {
            $sizes[$file_type] .= ' files)';
          }
        }
      }

      $class = array(
        'Class: ' . $definition['class'],
        'Classfile: ' . $instance->getClassPath(),
      );

      $rows[] = array(
        $instance->getProvider(),
        $instance->getBaseId(),
        implode('<br/>', $class),
        implode('|', $definition['arguments']),
        $sizes['js'],
        $sizes['css'],
      );
    }

    $header = array(
      'Module provider',
      'ID',
      'Class',
      'Arguments',
      'JS size',
      'CSS size',
    );
    $table = theme(
      'table',
      array(
        'header' => $header,
        'rows' => $rows,
        'empty' => t('No plugin available.'),
      )
    );

    $form['plugin-info'][$plugin_type . '-group']['table'] = array(
      '#markup' => $table,
    );
  }

  $form['buttons'] = array(
    'submit' => array(
      '#type' => 'submit',
      '#value' => 'Save configuration',
    ),
  );

  return $form;
}

/**
 * Submit callback of the Openlayers settings page.
 */
function openlayers_ui_admin_settings_submit($form, &$form_state) {
  $values = $form_state['values'];

  if (isset($values['variant'])) {
    \Drupal\openlayers\Config::set('openlayers.variant', $values['variant']);
  }
  else {
    \Drupal\openlayers\Config::clear('openlayers.variant');
  }

  if (isset($values['debug'])) {
    \Drupal\openlayers\Config::set('openlayers.debug', $values['debug']);
  }
  else {
    \Drupal\openlayers\Config::clear('openlayers.debug');
  }

  drupal_set_message(t('The configuration options have been saved.'));
  drupal_flush_all_caches();
}
