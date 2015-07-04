<?php
/**
 * @file
 * CTools Export UI plugin definition for maps.
 */

/**
 * CTools Export UI plugin definition.
 */
function openlayers_ui_OpenlayersMaps_ctools_export_ui() {
  return array(
    'schema' => 'openlayers_maps',
    'access' => 'administer openlayers',
    'menu' => array(
      'menu prefix' => 'admin/structure/openlayers',
      'menu item' => 'maps',
      'menu title' => 'Maps',
      'menu description' => 'Administer OpenLayers maps presets.',
    ),

    'handler' => array(
      'class' => '\\Drupal\\openlayers_ui\\UI\\OpenlayersMaps',
      'file' => 'OpenlayersMaps.php',
    ),

    'use wizard' => TRUE,
    'form info' => array(
      'order' => array(
        'start' => t('Administrative settings'),
        'settings' => t('Map settings'),
        'layers' => t('Layers and sources'),
        'controls' => t('Controls'),
        'interactions' => t('Interactions'),
        'components' => t('Components'),
        'styles' => t('Styles'),
        'preview' => t('Preview'),
      ),
      'forms' => array(
        'start' => array(
          'form id' => 'openlayers_map_form_start',
        ),
        'settings' => array(
          'form id' => 'openlayers_map_form_settings',
        ),
        'layers' => array(
          'form id' => 'openlayers_map_form_layers',
        ),
        'controls' => array(
          'form id' => 'openlayers_map_form_controls',
        ),
        'interactions' => array(
          'form id' => 'openlayers_map_form_interactions',
        ),
        'components' => array(
          'form id' => 'openlayers_map_form_components',
        ),
        'styles' => array(
          'form id' => 'openlayers_map_form_styles',
        ),
        'preview' => array(
          'form id' => 'openlayers_map_form_preview',
        ),
      ),
      'wrapper' => 'openlayers_objects_ui_form_wrapper',
    ),

    'export' => array(
      'admin_title' => 'name',
      'admin_description' => 'description',
    ),

    'title singular' => t('map'),
    'title plural' => t('maps'),
    'title singular proper' => t('OpenLayers map preset'),
    'title plural proper' => t('OpenLayers maps presets'),

    'strings' => array(
      'confirmation' => array(
        'add' => array(
          'success' => t('Map saved.'),
        ),
        'delete' => array(
          'success' => t('Map was deleted.'),
        ),
      ),
    ),
  );
}

/**
 * Map base config form handler.
 */
function openlayers_map_form_start($form, &$form_state) {
  $class = new Drupal\openlayers_ui\UI\OpenlayersMaps();
  $class->init($form_state['plugin']);
  $class->edit_form($form, $form_state);
  return $form;
}

/**
 * Map base config form validation handler.
 */
function openlayers_map_form_start_validate($form, &$form_state) {
  $class = new Drupal\openlayers_ui\UI\OpenlayersMaps();
  $class->init($form_state['plugin']);
  $class->edit_form_validate($form, $form_state);
}

/**
 * Map base config form submit handler.
 */
function openlayers_map_form_start_submit($form, &$form_state) {
  $class = new Drupal\openlayers_ui\UI\OpenlayersMaps();
  $class->init($form_state['plugin']);
  $class->edit_form_submit($form, $form_state);
}

/**
 * Map settings config form handler.
 */
function openlayers_map_form_settings($form, &$form_state) {
  if (!isset($form_state['item']->factory_service)) {
    $form_state['item']->factory_service = 'openlayers.Map:OLMap';
  }
  if (($map = \Drupal\openlayers\Openlayers::load('Map', $form_state['item'])) == TRUE) {
    $map->optionsForm($form, $form_state);
    $form['options']['#tree'] = TRUE;
  }

  return $form;
}

/**
 * Map settings config form validation handler.
 */
function openlayers_map_form_settings_validate($form, &$form_state) {
  $item = $form_state['item'];
  if (empty($item->factory_service)) {
    $item->factory_service = 'openlayers.Map:OLMap';
  }
  if (isset($form_state['values']['options'])) {
    $form_state['item']->options = array_merge((array) $form_state['item']->options, (array) $form_state['values']['options']);
  }

  if (($map = \Drupal\openlayers\Openlayers::load('Map', $item)) == TRUE) {
    $map->optionsFormValidate($form, $form_state);
  }
}

/**
 * Map settings config form submit handler.
 */
function openlayers_map_form_settings_submit($form, &$form_state) {
  // todo: fix.
  if (empty($form_state['item']->factory_service)) {
    $form_state['item']->factory_service = 'openlayers.Map:OLMap';
  }
  if (isset($form_state['values']['options'])) {
    $form_state['item']->options = array_merge((array) $form_state['item']->options, (array) $form_state['values']['options']);
  }

  if (($map = \Drupal\openlayers\Openlayers::load('Map', $form_state['item'])) == TRUE) {
    $map->optionsFormSubmit($form, $form_state);
  }
}

/**
 * Map layers config form handler.
 */
function openlayers_map_form_layers($form, &$form_state) {
  $all_layers = \Drupal\openlayers\Openlayers::loadAllExportable('Layer');
  if (($map = \Drupal\openlayers\Openlayers::load('Map', $form_state['item'])) == FALSE) {
    return;
  }

  $layers = array();
  foreach ($map->getObjects('layer') as $layer) {
    if (is_object($layer) && isset($all_layers[$layer->machine_name])) {
      $layers[$layer->machine_name] = $all_layers[$layer->machine_name];
      $layers[$layer->machine_name]->enable = 1;
      unset($all_layers[$layer->machine_name]);
    }
  }

  $layers = array_merge($layers, $all_layers);

  $data = array();

  $i = 0;
  /* @var \Drupal\openlayers\Types\Layer $layer */
  foreach ($layers as $machine_name => $layer) {
    if (is_object($layer)) {
      $data[$machine_name] = array(
        'name' => $layer->name,
        'machine_name' => $layer->machine_name,
        'factory_service' => $layer->factory_service,
        'weight' => $i++,
        'enable' => isset($layer->enable) ? $layer->enable : 0,
        'default' => 1,
        'style' => isset($layer->options['style']) ? $layer->options['style'] : NULL
      );
    }
  }

  $rows = array();
  $row_elements = array();
  foreach ($data as $id => $entry) {
    $rows[$id] = array(
      'data' => array(
        array('class', array('entry-cross')),
        array(
          'data' => array(
            '#type' => 'weight',
            '#title' => t('Weight'),
            '#title_display' => 'invisible',
            '#default_value' => $entry['weight'],
            '#parents' => array('layers', $id, 'weight'),
            '#attributes' => array(
              'class' => array('entry-order-weight'),
            ),
          )),
        array(
          'data' => array(
            '#type' => 'checkbox',
            '#title' => t('Enable'),
            '#title_display' => 'invisible',
            '#default_value' => $entry['enable'],
            '#parents' => array('layers', $id, 'enable'),
          )),
        array(
          'data' => array(
            '#type' => 'select',
            '#title' => t('Style'),
            '#title_display' => 'invisible',
            '#options' => array('' => t('- Select a Style -')) + \Drupal\openlayers\Openlayers::loadAllAsOptions('style'),
            '#default_value' => $entry['style'],
            '#parents' => array('layers', $id, 'style'),
          )
        ),
        array(
          'data' => array(
            '#type' => 'hidden',
            '#default_value' => $entry['machine_name'],
            '#parents' => array('layers', $id, 'machine_name'),
          )),
        check_plain($entry['name']),
        check_plain($entry['machine_name']),
        check_plain($entry['factory_service']),
        l(t('Edit'), 'admin/structure/openlayers/layers/list/' . $entry['machine_name'] . '/edit/options',
          array(
            'query' => array(
              'destination' => current_path(),
            ),
          )
        ),
      ),
      'class' => array('draggable'),
    );
    // Build rows of the form elements in the table.
    $row_elements[$id] = array(
      'weight' => &$rows[$id]['data'][1]['data'],
      'enabled' => &$rows[$id]['data'][2]['data'],
      'style' => &$rows[$id]['data'][3]['data'],
      'machine_name' => &$rows[$id]['data'][4]['data'],
    );
  }

  $form['layers'] = array(
    '#type' => 'fieldset',
    '#title' => 'Layers',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  // Add the table to the form.
  $form['layers']['table_layers'] = array(
    '#theme' => 'table',
    // The row form elements need to be processed and build,
    // therefore pass them as element children.
    'elements' => $row_elements,
    '#header' => array(
      // We need two empty columns for the weigth field and the cross.
      array('data' => NULL, 'colspan' => 2),
      t('Enabled'),
      array('data' => t('Style'), 'colspan' => 1),
      t('Name'),
      t('Machine name'),
      t('Style'),
      t('Factory service'),
      t('Operations'),
    ),
    '#rows' => $rows,
    '#empty' => t('There are no entries available.'),
    '#attributes' => array('id' => 'entry-order-layers'),
  );
  drupal_add_tabledrag('entry-order-layers', 'order', 'sibling', 'entry-order-weight');

  $all_sources = \Drupal\openlayers\Openlayers::loadAllExportable('Source');

  $sources = array();
  /* @var \Drupal\openlayers\Types\Map $map */
  if (($map = \Drupal\openlayers\Openlayers::load('Map', $form_state['item'])) == TRUE) {
    foreach ($map->getObjects('source') as $source) {
      if (isset($all_sources[$source->machine_name])) {
        $sources[$source->machine_name] = $all_sources[$source->machine_name];
        $sources[$source->machine_name]->enable = 1;
        unset($all_sources[$source->machine_name]);
      }
    }
  }

  $sources = array_merge($sources, $all_sources);

  $data = array();

  $i = 0;
  foreach ($sources as $machine_name => $source) {
    if (is_object($source)) {
      $data[$machine_name] = array(
        'name' => $source->name,
        'machine_name' => $source->machine_name,
        'factory_service' => $source->factory_service,
        'weight' => $i++,
        'enable' => isset($source->enable) ? $source->enable : 0,
        'default' => 1,
      );
    }
  }

  $rows = array();
  foreach ($data as $id => $entry) {
    $rows[$id] = array(
      'data' => array(
        array('class', array('entry-cross')),
        array(
          'data' => array(
            '#type' => 'weight',
            '#title' => t('Weight'),
            '#title_display' => 'invisible',
            '#default_value' => $entry['weight'],
            '#parents' => array('sources', $id, 'weight'),
            '#attributes' => array(
              'class' => array('entry-order-weight'),
            ),
          )),
        array(
          'data' => array(
            '#type' => 'checkbox',
            '#title' => t('Enable'),
            '#title_display' => 'invisible',
            '#default_value' => $entry['enable'],
            '#parents' => array('sources', $id, 'enable'),
          )),
        check_plain($entry['name']),
        check_plain($entry['machine_name']),
        check_plain($entry['factory_service']),
        l(t('Edit'), 'admin/structure/openlayers/sources/list/' . $entry['machine_name'] . '/edit/options',
          array(
            'query' => array(
              'destination' => current_path(),
            ),
          )
        ),
      ),
      'class' => array('draggable'),
    );
    // Build rows of the form elements in the table.
    $row_elements[$id] = array(
      'weight' => &$rows[$id]['data'][1]['data'],
      'enabled' => &$rows[$id]['data'][2]['data'],
    );
  }

  $form['sources'] = array(
    '#type' => 'fieldset',
    '#title' => 'Sources',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Add the table to the form.
  $form['sources']['table_sources'] = array(
    '#theme' => 'table',
    // The row form elements need to be processed and build,
    // therefore pass them as element children.
    'elements' => $row_elements,
    '#header' => array(
      // We need two empty columns for the weigth field and the cross.
      array('data' => NULL, 'colspan' => 2),
      t('Enabled'),
      t('Name'),
      t('Machine name'),
      t('Class'),
      t('Operations'),
    ),
    '#rows' => $rows,
    '#empty' => t('There are no entries available.'),
    '#attributes' => array('id' => 'entry-order-sources'),
  );
  drupal_add_tabledrag('entry-order-sources', 'order', 'sibling', 'entry-order-weight');

  return $form;
}

/**
 * Map layers config form submit handler.
 */
function openlayers_map_form_layers_submit($form, &$form_state) {
  $layers = $form_state['values']['layers'];

  $layers_enabled = array();
  foreach ($layers as $id => $data) {
    if ($data['enable'] == 1) {
      //Update the weight.
      $layers_enabled[$data['weight']] = $id;

      //Update the layer style.
      if (($layer = \Drupal\openlayers\Openlayers::load('layer', $data['machine_name'])) == TRUE) {
        if (!is_null($data['style'])) {
          if ($data['style'] != $layer->getOption('style')) {
            $layer->setOption('style', $data['style']);
          }
        }
        else {
          $layer->clearOption('style');
        }
        \Drupal\openlayers\Openlayers::save($layer);
      }
    }
  }

  ksort($layers_enabled);

  $sources = $form_state['values']['sources'];

  $sources_enabled = array();
  foreach ($sources as $id => $data) {
    if ($data['enable'] == 1) {
      $sources_enabled[$data['weight']] = $id;
    }
  }

  ksort($sources_enabled);

  $form_state['item']->options['layers'] = array_values($layers_enabled);
  $form_state['item']->options['sources'] = array_values($sources_enabled);
}

/**
 * Map controls config form handler.
 */
function openlayers_map_form_controls($form, &$form_state) {
  $all_controls = \Drupal\openlayers\Openlayers::loadAllExportable('Control');

  if (!isset($form_state['item']->options['controls'])) {
    $form_state['item']->options['controls'] = array();
  }

  $data = array();

  // Ensure the controls are ordered correctly.
  foreach (array_reverse($form_state['item']->options['controls']) as $machine_name) {
    if (isset($all_controls[$machine_name])) {
      $control = $all_controls[$machine_name];
      $all_controls = array($machine_name => $control) + $all_controls;
    }
  }

  $i = 0;
  foreach ($all_controls as $machine_name => $control) {
    if (is_object($control)) {
      $data[$machine_name] = array(
        'name' => $control->name,
        'machine_name' => $control->machine_name,
        'description' => $control->description,
        'weight' => $i++,
        'enable' => (int) in_array($control->machine_name, $form_state['item']->options['controls']),
        'default' => 1,
      );
    }
  }

  $rows = array();
  $row_elements = array();
  foreach ($data as $id => $entry) {
    $rows[$id] = array(
      'data' => array(
        array(
          'class',
          array(
            'entry-cross'
          )
        ),
        array(
          'data' => array(
            '#type' => 'weight',
            '#title' => t('Weight'),
            '#title_display' => 'invisible',
            '#default_value' => $entry['weight'],
            '#parents' => array('controls', $id, 'weight'),
            '#attributes' => array(
              'class' => array('entry-order-weight'),
            ),
          )
        ),
        array(
          'data' => array(
            '#type' => 'checkbox',
            '#title' => t('Enable'),
            '#title_display' => 'invisible',
            '#default_value' => $entry['enable'],
            '#parents' => array('controls', $id, 'enable'),
          )
        ),
        check_plain($entry['name']),
        check_plain($entry['machine_name']),
        check_plain($entry['description']),
        l(t('Edit'), 'admin/structure/openlayers/controls/list/' . $entry['machine_name'] . '/edit',
          array(
            'query' => array(
              'destination' => current_path(),
            ),
          )
        ),
      ),
      'class' => array('draggable'),
    );
    // Build rows of the form elements in the table.
    $row_elements[$id] = array(
      'weight' => &$rows[$id]['data'][1]['data'],
      'enabled' => &$rows[$id]['data'][2]['data'],
    );
  }

  $form['options']['#tree'] = TRUE;

  // Add the table to the form.
  $form['controls']['table_controls'] = array(
    '#theme' => 'table',
    // The row form elements need to be processed and build,
    // therefore pass them as element children.
    'elements' => $row_elements,
    '#header' => array(
      // We need two empty columns for the weigth field and the cross.
      array('data' => NULL, 'colspan' => 2),
      t('Enabled'),
      t('Name'),
      t('Machine name'),
      t('Description'),
      t('Operations'),
    ),
    '#rows' => $rows,
    '#empty' => t('There are no entries available.'),
    '#attributes' => array('id' => 'entry-order-controls'),
  );
  drupal_add_tabledrag('entry-order-controls', 'order', 'sibling', 'entry-order-weight');

  return $form;
}

/**
 * Map controls config form submit handler.
 */
function openlayers_map_form_controls_submit($form, &$form_state) {
  $controls = $form_state['values']['controls'];

  $controls_enabled = array();
  foreach ($controls as $id => $data) {
    if (!empty($data['enable'])) {
      $controls_enabled[$data['weight']] = $id;
    }
  }
  ksort($controls_enabled);

  $form_state['item']->options['controls'] = array_values($controls_enabled);
}

/**
 * Map interactions config form handler.
 */
function openlayers_map_form_interactions($form, &$form_state) {
  $all_interactions = \Drupal\openlayers\Openlayers::loadAllExportable('Interaction');

  $header = array(
    'name' => t('Name'),
    'machine_name' => t('Machine name'),
    'description' => t('Description'),
    'operations' => t('Operations'),
  );

  $rows = array();
  foreach ($all_interactions as $machine_name => $interaction) {
    if (is_object($interaction)) {
      $rows[$machine_name] = array(
        'name' => $interaction->name,
        'machine_name' => $interaction->machine_name,
        'description' => $interaction->description,
        'operations' => l(
          t('Edit'),
          'admin/structure/openlayers/interactions/list/' . $machine_name . '/edit/options',
          array(
            'query' => array(
              'destination' => current_path(),
            ),
          )
        ),
      );
    }
  }

  $form['options']['#tree'] = TRUE;

  if (!isset($form_state['item']->options['interactions'])) {
    $form_state['item']->options['interactions'] = array();
  }

  $form['options']['interactions'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $rows,
    '#default_value' => drupal_map_assoc($form_state['item']->options['interactions']),
  );

  return $form;
}

/**
 * Map interactions config form submit handler.
 */
function openlayers_map_form_interactions_submit($form, &$form_state) {
  if (isset($form_state['values']['options'])) {
    $form_state['item']->options = array_merge((array) $form_state['item']->options, (array) $form_state['values']['options']);
  }
  $form_state['item']->options['interactions'] = array_filter(array_values($form_state['values']['options']['interactions']));
}

/**
 * Map components config form handler.
 */
function openlayers_map_form_components($form, &$form_state) {
  $all_components = \Drupal\openlayers\Openlayers::loadAllExportable('Component');

  if (!isset($form_state['item']->options['controls'])) {
    $form_state['item']->options['controls'] = array();
  }

  $data = array();

  // Ensure the components are ordered correctly.
  foreach (array_reverse($form_state['item']->options['components']) as $machine_name) {
    if (isset($all_components[$machine_name])) {
      $component = $all_components[$machine_name];
      $all_components = array($machine_name => $component) + $all_components;
    }
  }

  $i = 0;
  foreach ($all_components as $machine_name => $component) {
    if (is_object($component)) {
      $data[$machine_name] = array(
        'name' => $component->name,
        'machine_name' => $component->machine_name,
        'description' => $component->description,
        'weight' => $i++,
        'enable' => (int) in_array($component->machine_name, $form_state['item']->options['components']),
        'default' => 1,
      );
    }
  }

  $rows = array();
  $row_elements = array();
  foreach ($data as $id => $entry) {
    $rows[$id] = array(
      'data' => array(
        array('class', array('entry-cross')),
        array(
          'data' => array(
            '#type' => 'weight',
            '#title' => t('Weight'),
            '#title_display' => 'invisible',
            '#default_value' => $entry['weight'],
            '#parents' => array('components', $id, 'weight'),
            '#attributes' => array(
              'class' => array('entry-order-weight'),
            ),
          )),
        array(
          'data' => array(
            '#type' => 'checkbox',
            '#title' => t('Enable'),
            '#title_display' => 'invisible',
            '#default_value' => $entry['enable'],
            '#parents' => array('components', $id, 'enabled'),
          )),
        check_plain($entry['name']),
        check_plain($entry['machine_name']),
        check_plain($entry['description']),
        l(t('Edit'), 'admin/structure/openlayers/components/list/' . $entry['machine_name'] . '/edit',
          array(
            'query' => array(
              'destination' => current_path(),
            ),
          )
        ),
      ),
      'class' => array('draggable'),
    );
    // Build rows of the form elements in the table.
    $row_elements[$id] = array(
      'weight' => &$rows[$id]['data'][1]['data'],
      'enabled' => &$rows[$id]['data'][2]['data'],
    );
  }

  $form['options']['#tree'] = TRUE;

  // Add the table to the form.
  $form['components']['table_components'] = array(
    '#theme' => 'table',
    // The row form elements need to be processed and build,
    // therefore pass them as element children.
    'elements' => $row_elements,
    '#header' => array(
      // We need two empty columns for the weight field and the cross.
      array('data' => NULL, 'colspan' => 2),
      t('Enabled'),
      t('Name'),
      t('Machine name'),
      t('Description'),
      t('Operations'),
    ),
    '#rows' => $rows,
    '#empty' => t('There are no entries available.'),
    '#attributes' => array('id' => 'entry-order-components'),
  );
  drupal_add_tabledrag('entry-order-components', 'order', 'sibling', 'entry-order-weight');

  return $form;
}

/**
 * Map components config form submit handler.
 */
function openlayers_map_form_components_submit($form, &$form_state) {
  if (isset($form_state['values']['options'])) {
    $form_state['item']->options = array_merge((array) $form_state['item']->options, (array) $form_state['values']['options']);
  }
  $components = $form_state['values']['components'];

  $components_enabled = array();
  foreach ($components as $id => $data) {
    if (!empty($data['enabled'])) {
      $components_enabled[$data['weight']] = $id;
    }
  }
  ksort($components_enabled);

  $form_state['item']->options['components'] = array_values($components_enabled);
}

/**
 * Map styles config form handler.
 */
function openlayers_map_form_styles($form, &$form_state) {
  return $form;
}

/**
 * Map styles config form submit handler.
 */
function openlayers_map_form_styles_submit($form, &$form_state) {
  // $form_state['item']->options = $form_state['item']->options, (array) $form_state['values']['options']);
}

/**
 * Map preview form handler.
 */
function openlayers_map_form_preview($form, &$form_state) {
  if (($map = \Drupal\openlayers\Openlayers::load('Map', $form_state['item'])) == TRUE) {
    $form['preview'] = $map->build();
  }
  return $form;
}

/**
 * Map preview config form submit handler.
 */
function openlayers_map_form_preview_submit($form, &$form_state) {

}

/**
 * Helper function to sort an array by item weight.
 */
function _openlayers_maps_sort_by_weight($a, $b) {
  if (isset($a['weight']) && isset($b['weight'])) {
    return $a['weight'] < $b['weight'] ? -1 : 1;
  }
  return 0;
}
