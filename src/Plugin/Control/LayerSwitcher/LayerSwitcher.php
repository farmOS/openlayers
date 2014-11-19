<?php
/**
 * @file
 * Control: LayerSwitcher.
 *
 * Proof of concept based on http://geocre.github.io/ol3/layerswitcher.html
 */

namespace Drupal\openlayers\Control;
use Drupal\openlayers\Control;

/**
 * Class LayerSwitcher
 *
 * @package Drupal\openlayers\Control
 */
class LayerSwitcher extends Control {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['layers'] = array(
      '#type' => 'select',
      '#title' => t('Layers'),
      '#multiple' => TRUE,
      '#default_value' => $this->getOption('layers'),
      '#options' => openlayers_layer_options(FALSE),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function preBuild(array &$build, \Drupal\openlayers\ObjectInterface $context = NULL) {
    $map_id = $context->getId();
    $layers = $this->getOption('layers', array());
    $items = array();
    $map_layers = $context->getLayers();

    // Only handle layers available in the map and configured in the control.
    foreach ($map_layers as $i => $map_layer) {
      if (isset($layers[$map_layer->machine_name])) {
        $items[] = array(
          'data' => '<label><input type="radio" name="layer" value="' . $map_layer->machine_name . '">' . $map_layer->machine_name . '</label>',
          'id' => $map_id . '-' . $map_layer->machine_name,
          'class' => array(drupal_html_class($map_layer->machine_name)),
        );
      }
    }

    $layerswitcher = array(
      '#theme' => 'item_list',
      '#type' => 'ul',
      '#title' => t('LayerSwitcher'),
      '#items' => $items,
      '#attributes' => array(
        'id' => drupal_html_id($this->machine_name),
      ),
    );
    $this->setOption('element', '<div id="' . drupal_html_id($this->machine_name) . '" class="layerswitcher">' . drupal_render($layerswitcher) . '</div>');
  }
}
