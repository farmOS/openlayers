<?php
/**
 * @file
 * Class openlayers_map.
 */

namespace Drupal\openlayers;

/**
 * Class openlayers_map.
 */
class Map extends Object implements MapInterface {

  /**
   * @var string
   */
  protected $id;

  /**
   * {@inheritdoc}
   */
  public function init(array $data) {
    parent::init($data);

    $this->setOption('target', $this->getId());
  }

  /**
   * {@inheritdoc}
   */
  public function getId() {
    if (isset($this->id)) {
      return $this->id;
    }

    $css_map_name = drupal_clean_css_identifier($this->machine_name);
    $this->id = drupal_html_id('openlayers-map-' . $css_map_name);
    return $this->id;
  }

  /**
   * {@inheritdoc}
   */
  public function getLayers() {
    $result = array();
    foreach ($this->getOption('layers', array()) as $layer) {
      $result[] = clone openlayers_object_load('layer', $layer);
    }
    return $result;
  }

  /**
   * {@inheritdoc}
   */
  public function getSources() {
    $sources = array();
    foreach ($this->getOption('sources', array()) as $index => $source) {
      $sources[$source] = openlayers_object_load('source', $source);
    }

    // Add sources required / defined by the assigned layers.
    foreach ($this->getLayers() as $index => $layer) {
      if ($source = $layer->getSource()) {
        $sources[$source->machine_name] = $source;
      }
    }

    // We set the machine name as key of the sources to avoid duplicated
    // listing. But we return an array without associative keys.
    return array_values($sources);
  }

  /**
   * {@inheritdoc}
   */
  public function getStyles() {
    $styles = array();
    foreach ($this->getOption('styles', array()) as $source) {
      $styles[] = openlayers_object_load('style', $source);
    }

    foreach ($this->getLayers() as $layer) {
      if ($style = $layer->getStyle()) {
        $styles[] = $style;
      }
    }

    return $styles;
  }

  /**
   * {@inheritdoc}
   */
  public function getControls() {
    $result = array();
    foreach ($this->getOption('controls', array()) as $control) {
      $result[] = clone openlayers_object_load('control', $control);
    }
    return $result;
  }

  /**
   * {@inheritdoc}
   */
  public function getInteractions() {
    $result = array();
    foreach ($this->getOption('interactions', array()) as $interaction) {
      $result[] = clone openlayers_object_load('interaction', $interaction);
    }
    return $result;
  }

  /**
   * {@inheritdoc}
   */
  public function getComponents() {
    $result = array();
    foreach ($this->getOption('components', array()) as $component) {
      $result[] = clone openlayers_object_load('component', $component);
    }
    return $result;
  }

  /**
   * {@inheritdoc}
   */
  public function develop() {
    if ($layers = $this->getLayers()) {
      $this->options['layers'] = array();
      foreach ($layers as $data) {
        $object = clone openlayers_object_load('layer', $data);
        $this->options['layers'][] = $object;
      }
    }
    if ($controls = $this->getControls()) {
      $this->options['controls'] = array();
      foreach ($controls as $data) {
        $object = clone openlayers_object_load('control', $data);
        $this->options['controls'][] = $object;
      }
    }
    if ($interactions = $this->getInteractions()) {
      $this->options['interactions'] = array();
      foreach ($interactions as $index => $data) {
        $object = clone openlayers_object_load('interaction', $data);
        $this->options['interactions'][] = $object;
      }
    }
    if ($components = $this->getComponents()) {
      $this->options['components'] = array();
      foreach ($components as $index => $data) {
        $object = clone openlayers_object_load('component', $data);
        $this->options['components'][] = $object;
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getObjects() {
    $objects = array();
    $objects['layer'] = $this->getLayers();
    $objects['style'] = $this->getStyles();
    $objects['source'] = $this->getSources();
    $objects['control'] = $this->getControls();
    $objects['interaction'] = $this->getInteractions();
    $objects['component'] = $this->getComponents();

    $objects = unserialize(serialize($objects));

    foreach ($objects['layer'] as $index => $layer) {
      if ($source = $layer->getSource()) {
        $objects['layer'][$index]->options['source'] = $source->machine_name;
      }
      if ($style = $layer->getStyle()) {
        $objects['layer'][$index]->options['style'] = $style->machine_name;
      }
    }

    return $objects;
  }

  /**
   * {@inheritdoc}
   */
  public function getJSObjects() {
    $objects = $this->getObjects();

    foreach (openlayers_object_types() as $type) {
      foreach ($objects[$type] as $index => $object) {
        $objects[$type][$index] = (array) $object->toJSArray();
      }
    }

    $objects['map'] = $this->toJSArray();

    $objects = array_map_recursive('_floatval_if_numeric', $objects);
    $objects = removeEmptyElements($objects);

    return $objects;
  }

  /**
   * {@inheritdoc}
   */
  public function attached(\Drupal\openlayers\ObjectInterface $context) {
    $this->attached = parent::attached($context);
    $objects = $this->getObjects();

    foreach ($objects as $type => $list) {
      if ($list != FALSE) {
        foreach ($list as $index => $data) {
          $this->attached = drupal_array_merge_deep($this->attached, $data->attached($context));
        }
      }
    }

    return $this->attached;
  }

  public function getType() {
    return 'Map';
  }
}
