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

    $options = array();
    foreach (\Drupal\openlayers\Openlayers::loadAll('map') as $map) {
      foreach($map->getCollection()->getObjects('layer') as $layer) {
        $key = $map->getMachineName() . ':' . $layer->getMachineName();
        $value = sprintf("%s: %s (%s)", $map->getName(), $layer->getName(), $layer->getMachineName());
        $options[$map->getName()][$key] = $value;
      }
    }

    $form['base_map_layer'] = array(
      '#type' => 'select',
      '#title' => 'Base map to use and vector layer to fill with the views features',
      '#description' => 'You may choose any vector layer only.',
      '#options' => $options,
      '#default_value' => $this->options['base_map_layer'],
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
    $style_plugin_options = $this->view->style_plugin->options;

    list($mapname, $layername) = explode(':', $style_plugin_options['base_map_layer'], 2);

    if (empty($this->view->style_plugin->options['skipMapRender'])) {
      if (($map = \Drupal\openlayers\Openlayers::load('Map', $mapname)) == TRUE && !($map instanceof \Drupal\openlayers\Types\Error)) {
        foreach($map->getCollection()->getObjects('layer') as $layer) {
          if ($layer->getMachineName() == $layername) {
            $source = \Drupal\openlayers\Openlayers::load('source', 'openlayers_views_source_' . $this->view->name . '_' . $this->view->current_display);
            $layer->setSource($source);
            $map->getCollection()->import(array($source));
          }
        }
        $output = $map->build();
      }
    } else {
      $grouped_results = $this->render_grouping($this->view->result, $this->options['grouping']);
      $output = $this->map_features($grouped_results);
    }

    return $output;
  }
}