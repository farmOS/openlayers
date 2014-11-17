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
   * Stores the objects related to this map.
   *
   * @see Map::getLayers()
   * @see Map::getSources()
   * @see Map::getStyles()
   * @see Map::getControls()
   * @see Map::getInteractions()
   * @see Map::getComponents()
   * @see Map::getObjects()
   *
   * @var array
   */
  protected $objects = array();

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
  public function getLayers($reset = FALSE) {
    if (!isset($this->objects['layer']) || $reset) {
      $this->objects['layer'] = array();
      foreach ($this->getOption('layers', array()) as $layer) {
        $this->objects['layer'][] = clone openlayers_object_load('layer', $layer);
      }
    }
    return $this->objects['layer'];
  }

  /**
   * {@inheritdoc}
   */
  public function getSources($reset = FALSE) {
    if (!isset($this->objects['source']) || $reset) {
      $this->objects['source'] = array();
      foreach ($this->getOption('sources', array()) as $index => $source) {
        $this->objects['source'][$source] = openlayers_object_load('source', $source);
      }

      // Add sources required / defined by the assigned layers.
      foreach ($this->getLayers() as $index => $layer) {
        if ($source = $layer->getSource()) {
          $this->objects['source'][$source->machine_name] = $source;
        }
      }

      // We set the machine name as key of the sources to avoid duplicated
      // listing. But we return an array without associative keys.
      $this->objects['source'] = array_values($this->objects['source']);
    }
    return $this->objects['source'];
  }

  /**
   * {@inheritdoc}
   */
  public function getStyles($reset = FALSE) {
    if (!isset($this->objects['style']) || $reset) {
      $this->objects['style'] = array();
      foreach ($this->getOption('styles', array()) as $source) {
        $this->objects['style'][] = openlayers_object_load('style', $source);
      }

      foreach ($this->getLayers() as $layer) {
        if ($style = $layer->getStyle()) {
          $this->objects['style'][] = $style;
        }
      }
    }
    return $this->objects['style'];
  }

  /**
   * {@inheritdoc}
   */
  public function getControls($reset = FALSE) {
    if (!isset($this->objects['control']) || $reset) {
      $this->objects['control'] = array();
      foreach ($this->getOption('controls', array()) as $control) {
        $this->objects['control'][] = clone openlayers_object_load('control', $control);
      }
    }
    return $this->objects['control'];
  }

  /**
   * {@inheritdoc}
   */
  public function getInteractions($reset = FALSE) {
    if (!isset($this->objects['interaction']) || $reset) {
      $this->objects['interaction'] = array();
      foreach ($this->getOption('interactions', array()) as $interaction) {
        $this->objects['interaction'][] = clone openlayers_object_load('interaction', $interaction);
      }
    }
    return $this->objects['interaction'];
  }

  /**
   * {@inheritdoc}
   */
  public function getComponents($reset = FALSE) {
    if (!isset($this->objects['component']) || $reset) {
      $this->objects['component'] = array();
      foreach ($this->getOption('components', array()) as $component) {
        $this->objects['component'][] = clone openlayers_object_load('component', $component);
      }
    }
    return $this->objects['component'];
  }

  /**
   * {@inheritdoc}
   */
  public function develop() {
    if ($layers = $this->getLayers()) {
      $this->options['layers'] = $layers;
    }
    if ($controls = $this->getControls()) {
      $this->options['controls'] = $controls;
    }
    if ($interactions = $this->getInteractions()) {
      $this->options['interactions'] = $interactions;
    }
    if ($components = $this->getComponents()) {
      $this->options['components'] = $components;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function &getObjects($reset = FALSE) {
    $this->getLayers($reset);
    $this->getStyles($reset);
    $this->getSources($reset);
    $this->getControls($reset);
    $this->getInteractions($reset);
    $this->getComponents($reset);

    foreach ($this->objects['layer'] as $index => $layer) {
      if ($source = $layer->getSource()) {
        $this->objects['layer'][$index]->options['source'] = $source->machine_name;
      }
      if ($style = $layer->getStyle()) {
        $this->objects['layer'][$index]->options['style'] = $style->machine_name;
      }
    }
    return $this->objects;
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
    $objects = unserialize(serialize($objects));

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
