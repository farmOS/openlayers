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

  $result_cdnjs = _openlayers_drupal_http_request('http://api.cdnjs.com/libraries?search=ol3&fields=assets');
  $result_jsdelivr = _openlayers_drupal_http_request('http://api.jsdelivr.com/v1/jsdelivr/libraries/ol3');
  $library = \Drupal\openlayers\Openlayers::getLibrary();

  $method = \Drupal\openlayers\Config::get('openlayers.origin.method', 'cdnjs');
  if (isset($form_state['values']['method'])) {
    $method = $form_state['values']['method'];
  }

  $version = \Drupal\openlayers\Config::get('openlayers.origin.version');
  if (isset($form_state['values']['version'])) {
    $version = $form_state['values']['version'];
  }

  $form['origin'] = array(
    '#type' => 'fieldset',
    '#title' => 'Library loading configuration',
    '#prefix' => '<div id="openlayers_origin">',
    '#suffix' => '</div>',
  );

  $form['origin']['method'] = array(
    '#type' => 'select',
    '#title' => 'Select the loading origin for your Openlayers JS library',
    '#options' => array(
      'jsdelivr' => 'jsDelivr',
      'cdnjs' => 'CDNJS',
      'local' => 'Locally'
    ),
    '#default_value' => $method,
    '#ajax' => array(
      'callback' => '_openlayers_ajax_reload_origin',
      'method' => 'replace',
      'wrapper' => 'openlayers_origin',
      'effect' => 'fade',
    ),
  );

  if ($method == 'local') {
    if ($library['installed'] == TRUE) {
      $variant_options = array_combine(array_keys($library['variants']), array_keys($library['variants']));
      $form['origin']['variant'] = array(
        '#type' => 'select',
        '#title' => t('Openlayers variant'),
        '#description' => t('Enabled this option if you want to use a specific variant of the library - maybe your own distribution.'),
        '#empty_option' => t('Auto'),
        '#options' => $variant_options,
        '#default_value' => \Drupal\openlayers\Config::get('openlayers.variant'),
      );

      $rows = array();
      $rows1 = array('name', 'vendor url', 'download url', 'library path', 'version');
      $header = array('Property', 'Value');
      foreach ($rows1 as $row) {
        $rows[] = array(
          $row,
          $library[$row],
        );
      }
      $output = theme('table', array('header' => $header, 'rows' => $rows));
    }
    else {
      $output = t('Openlayers library was not found. To install it, <a href="@url">download it manually</a> or use <em>drush dl-openlayers</em>. The library directory must be named <em>openlayers3</em> to be recognized by this module.', array('@url' => $library['download url']));
    }

    $form['origin']['library'] = array(
      '#markup' => $output
    );

  } else {
    $assets = array();
    if ($method == 'cdnjs') {
      if ($result_cdnjs->code == 200) {
        $result_cdnjs = json_decode($result_cdnjs->data, TRUE);
        foreach ((array) $result_cdnjs['results'][0]['assets'] as $asset) {
          $files = array();
          foreach($asset['files'] as $file) {
            $files[] = '//cdnjs.cloudflare.com/ajax/libs/ol3/' . $asset['version'] . '/' . $file;
          };
          $asset['files'] = $files;
          $assets[$asset['version']] = $asset;
        }
      }
    }

    if ($method == 'jsdelivr') {
      if ($result_jsdelivr->code == 200) {
        $result_jsdelivr = json_decode($result_jsdelivr->data, TRUE);
        foreach ((array) $result_jsdelivr[0]['assets'] as $asset) {
          $files = array();
          foreach($asset['files'] as $file) {
            $files[] = '//cdn.jsdelivr.net/ol3/' . $asset['version'] . '/' . $file;
          };
          $asset['files'] = $files;
          $assets[$asset['version']] = $asset;
        }
      }
    }

    if (!empty($assets)) {
      $form['origin']['version'] = array(
        '#type' => 'select',
        '#title' => 'Version available',
        '#options' => array_combine(array_keys($assets), array_keys($assets)),
        '#default_value' => \Drupal\openlayers\Config::get('openlayers.origin.version'),
        '#ajax' => array(
          'callback' => '_openlayers_ajax_reload_origin',
          'method' => 'replace',
          'wrapper' => 'openlayers_origin',
          'effect' => 'fade',
        ),
      );
    }

    $version_alt = key($assets);
    if (!is_string($version)) {
      $version = key($assets);
    }

    if (isset($assets[$version])) {
      $files = array();
      foreach((array) $assets[$version]['files'] as $file) {
        $files[$file] = $file;
      };

      $form['origin']['files'] = array(
        '#type' => 'checkboxes',
        '#title' => 'Files to load',
        '#options' => $files,
        '#default_value' => \Drupal\openlayers\Config::get('openlayers.origin.files', array()),
      );
    } else {
      if (isset($assets[$version_alt])) {
        $files = array();
        foreach((array) $assets[$version_alt]['files'] as $file) {
          $files[$file] = $file;
        };

        $form['origin']['files'] = array(
          '#type' => 'checkboxes',
          '#title' => 'Files to load',
          '#options' => $files,
          '#default_value' => \Drupal\openlayers\Config::get('openlayers.origin.files', array()),
        );
      } else {
        $form['origin']['files'] = array(
          '#type' => 'textarea',
          '#title' => 'Files to load',
          '#default_value' => trim(implode("\n", \Drupal\openlayers\Config::get('openlayers.origin.files', array()))),
        );
      }
    }
  }

  foreach (\Drupal\openlayers\Openlayers::loadAllExportable('Map') as $machine_name => $data) {
    if (!is_object($data) || (property_exists($data, 'disabled') && ($data->disabled == 1 || $data->disabled == TRUE))) {
      continue;
    }
    $options[$machine_name] = $data->name;
  }

  $map = \Drupal\openlayers\Config::get('openlayers.default_ui_map');
  if (isset($form_state['values']['openlayers_default_map'])) {
    $map = $form_state['values']['openlayers_default_map'];
  }

  // @todo: Is this setting really needed ?
  $form['openlayers_default_map'] = array(
    '#type' => 'select',
    '#title' => t('Default UI map'),
    '#options' => $options,
    '#default_value' => $map,
    '#ajax' => array(
      'callback' => '_openlayers_ajax_reload_default_map',
      'method' => 'replace',
      'wrapper' => 'default_map_ajax',
      'effect' => 'fade',
    ),
  );

  $form['default_ui_map'] = array(
    '#prefix' => '<div id="default_map_ajax">',
    '#suffix' => '</div>',
    '#type' => 'openlayers',
    '#map' => $map,
  );

  // This is for preventing 'system/ajax' as destination when using AJAX maps.
  // See: http://drupal.stackexchange.com/questions/86958/get-current-url-arguments-inside-ajax-callback
  $form['current_path'] = array('#type' => 'hidden', '#value' => current_path());

  $form['plugin-info'] = array(
    '#type' => 'fieldset',
    '#title' => 'Plugin information',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  foreach (\Drupal\openlayers\Openlayers::getPluginTypes() as $type) {
    $rows = array();

    $form['plugin-info'][$type . '-group'] = array(
      '#type' => 'fieldset',
      '#title' => $type,
      '#collapsed' => TRUE,
      '#collapsible' => TRUE,
    );

    foreach (\Drupal::service('openlayers.' . $type)->getDefinitions() as $service => $definition) {
      $definition += array('arguments' => array('NULL'));

      $configuration = array(
        'machine_name' => '',
        'factory_service' => '',
      );

      /* @var \Drupal\openlayers\Types\Object $instance */
      $instance = \Drupal::service('openlayers.' . $type)->createInstance($definition['id'], $configuration);
      $attached = $instance->attached();

      $sizes = array('js' => 0, 'css' => 0);
      foreach (array_keys($sizes) as $size_type) {
        foreach ($attached[$size_type] as $index => $data) {
          if (isset($data['type']) && $data['type'] != 'external') {
            if (!is_array($data['data'])) {
              $sizes[$size_type] += filesize($data['data']);
            }
          }
        }
      }

      if (count($attached['js']) != 0) {
        $sizes['js'] .= ' bytes.<br/>(' . count($attached['js']) . ' file(s))';
      }
      if (count($attached['css']) != 0) {
        $sizes['css'] .= 'bytes.<br/>(' . count($attached['css']) . ' file(s))';
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
    $table = theme('table', array('header' => $header, 'rows' => $rows, 'empty' => t('No plugin available.')));

    $form['plugin-info'][$type . '-group']['table'] = array(
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
 * @TODO: Document.
 */
function _openlayers_ajax_reload_default_map($form, &$form_state) {
  // This is for preventing 'system/ajax' as destination when using AJAX maps.
  // See: http://drupal.stackexchange.com/questions/86958/get-current-url-arguments-inside-ajax-callback
  $_SESSION['current_path'] = $form_state['input']['current_path'];
  return $form['default_ui_map'];
}

function _openlayers_ajax_reload_origin($form, &$form_stat) {
  return $form['origin'];
}

/**
 * Submit callback of the Openlayers settings page.
 */
function openlayers_ui_admin_settings_submit($form, &$form_state) {
  $values = $form_state['values'];
  \Drupal\openlayers\Config::set('openlayers.origin.method', $values['method']);

  if (isset($values['version'])) {
    \Drupal\openlayers\Config::set('openlayers.origin.version', $values['version']);
  } else {
    \Drupal\openlayers\Config::clear('openlayers.origin.version');
  }

  if (isset($values['files'])) {
    $files = $values['files'];
    if (is_string($files)) {
      $files = explode("\n", trim($files));
    } else {
      $files = array_filter($files);
    }
    \Drupal\openlayers\Config::set('openlayers.origin.files', $files);
  } else {
    \Drupal\openlayers\Config::clear('openlayers.origin.files');
  }

  if (isset($values['variant'])) {
    \Drupal\openlayers\Config::set('openlayers.variant', $values['variant']);
  } else {
    \Drupal\openlayers\Config::clear('openlayers.variant');
  }

  drupal_set_message(t('The configuration options have been saved.'));
}

function _openlayers_drupal_http_request($url, $options = array()) {
  $cache_name = 'openlayers.' . sha1($url);
  if (!cache_get($cache_name)) {
    $data = drupal_http_request($url, $options);
    cache_set($cache_name, $data, 'cache', REQUEST_TIME + 60);
    return $data;
  } else {
    $return = cache_get($cache_name);
    return($return->data);
  }
}
