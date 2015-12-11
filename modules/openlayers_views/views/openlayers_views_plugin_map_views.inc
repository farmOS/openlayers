<?php
/**
 * @file
 * Style handler that creates a map based on a view.
 */

/**
 * Class openlayers_views_plugin_map_views.
 */
class openlayers_views_plugin_map_views extends openlayers_views_plugin_style_source_vector {

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    $form['basemap'] = array(
      '#type' => 'select',
      '#title' => 'Base map',
      '#description' => 'This map will be used as template.',
      '#options' => \Drupal\openlayers\Openlayers::loadAllAsOptions('map'),
      '#default_value' => $this->options['basemap'],
      '#weight' => 1,
      '#required' => TRUE,
    );

    parent::options_form($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function render() {
    $output = NULL;

    // Fetch the features to use with the map.
    $live_preview = !empty($this->view->live_preview);
    $this->view->live_preview = FALSE;
    $this->features = parent::render();
    $this->view->live_preview = $live_preview;

    $style_plugin_options = $this->view->style_plugin->options;

    if (empty($this->skipMapRender) && ($map = \Drupal\openlayers\Openlayers::load('Map', $style_plugin_options['basemap'])) == TRUE && !($map instanceof \Drupal\openlayers\Types\Error)) {
      /** @var $layer \Drupal\openlayers\Types\LayerInterface */
      $layer = \Drupal\openlayers\Openlayers::load('layer', 'layer_map_views_' . $this->view->name . '_' . $this->view->current_display);
      $layer->getSource()->setOption('features', $this->features);
      $layer->setWeight(count($map->getCollection()->getObjects('layer')) + 1);
      $map->getCollection()->import(array($layer));
      $output = $map->build();
    }

    return $output;
  }

}
