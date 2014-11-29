<?php
/**
 * @file
 * Map: Map.
 */

namespace Drupal\openlayers\Map;
use Drupal\openlayers\Config;
use Drupal\openlayers\Types\Map;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Map\\OLMap',
);

/**
 * Class OLMap.
 */
class OLMap extends Map {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['ui'] = array(
      '#type' => 'fieldset',
      '#title' => t('Size of the map'),
      'width' => array(
        '#type' => 'textfield',
        '#title' => 'Width',
        '#default_value' => $this->getOption('width', 'auto'),
        '#parents' => array('options', 'width'),
      ),
      'height' => array(
        '#type' => 'textfield',
        '#title' => 'height',
        '#default_value' => $this->getOption('height', '300px'),
        '#parents' => array('options', 'height'),
      ),
    );

    $form['options']['view'] = array(
      '#type' => 'fieldset',
      '#title' => t('View: center and rotation'),
      '#tree' => TRUE,
    );

    if ($this->machine_name != Config::EDIT_VIEW_MAP) {
      $map = openlayers_object_load('Map', Config::EDIT_VIEW_MAP);
      if ($view = $this->getOption('view')) {
        $map->setOption('view', $view);
      }

      $form['options']['view']['map'] = array(
        '#type' => 'openlayers',
        '#description' => t('You can drag this map with your mouse, click to center and you can hold alt and shift key to rotate.'),
        '#map' => $map,
      );
    }

    $form['options']['view']['center'] = array(
      '#tree' => TRUE,
      'lat' => array(
        '#type' => 'textfield',
        '#title' => 'Latitude',
        '#default_value' => $this->getOption(array('view', 'center', 'lat'), 0),
      ),
      'lon' => array(
        '#type' => 'textfield',
        '#title' => 'Longitude',
        '#default_value' => $this->getOption(array('view', 'center', 'lat'), 0),
      ),
    );
    $form['options']['view']['rotation'] = array(
      '#type' => 'textfield',
      '#title' => 'Rotation',
      '#default_value' => $this->getOption(array('view', 'rotation'), 0),
    );
    $form['options']['view']['zoom'] = array(
      '#type' => 'textfield',
      '#title' => 'Zoom',
      '#default_value' => $this->getOption(array('view', 'zoom'), 0),
    );
    $form['options']['view']['minZoom'] = array(
      '#type' => 'textfield',
      '#title' => 'Min zoom',
      '#default_value' => $this->getOption(array('view', 'minZoom'), 0),
    );
    $form['options']['view']['maxZoom'] = array(
      '#type' => 'textfield',
      '#title' => 'Max zoom',
      '#default_value' => $this->getOption(array('view', 'maxZoom'), 0),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function attached() {
    $attached = parent::attached();
    // TODO: OpenLayers settings form by default to debug mode.
    $variant = Config::LIBRARY_VARIANT;
    $attached['libraries_load']['openlayers3'] = array('openlayers3', $variant);
    return $attached;
  }
}
