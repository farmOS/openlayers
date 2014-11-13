<?php
/**
 * @file
 * Component: Tooltip.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__component__tooltip_openlayers_component() {
  return array(
    'handler' => array(
      'class' => 'openlayers__component__tooltip',
      'file' => 'openlayers__component__tooltip.inc',
    ),
  );
}

/**
 * Class openlayers__component__tooltip.
 */
class openlayers__component__tooltip extends openlayers_component {

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    $layers = ctools_export_crud_load_all('openlayers_layers');
    $options = array('' => t('<Choose the layer>'));
    foreach ($layers as $machine_name => $data) {
      $options[$machine_name] = $data->name;
    }

    $form['options']['layer'] = array(
      '#type' => 'select',
      '#title' => t('Layer'),
      '#default_value' => isset($form_state['item']->options['layer']) ? $form_state['item']->options['layer'] : '',
      '#description' => t('Select the layer.'),
      '#options' => $options,
      '#required' => TRUE,
    );

    $form['options']['positioning'] = array(
      '#type' => 'select',
      '#title' => t('Positioning'),
      '#default_value' => isset($form_state['item']->options['positioning']) ? $form_state['item']->options['positioning'] : 'top-left',
      '#description' => t('Defines how the overlay is actually positioned. Default is top-left.'),
      '#options' => openlayers_positioning_options(),
      '#required' => TRUE,
    );
  }
}
