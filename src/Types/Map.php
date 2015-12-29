<?php
/**
 * @file
 * Class Map.
 */

namespace Drupal\openlayers\Types;

use Drupal\openlayers\Openlayers;

/**
 * Class Map.
 */
abstract class Map extends Object implements MapInterface {
  /**
   * A unique ID for the map.
   *
   * @var string
   */
  protected $id;

  /**
   * {@inheritdoc}
   *
   * @return MapInterface
   *   The Map object.
   */
  public function addLayer(LayerInterface $layer) {
    return $this->addObject($layer);
  }

  /**
   * {@inheritdoc}
   *
   * @return MapInterface
   *   The Map object.
   */
  public function addControl(ControlInterface $control) {
    return $this->addObject($control);
  }

  /**
   * {@inheritdoc}
   *
   * @return MapInterface
   *   The Map object.
   */
  public function addInteraction(InteractionInterface $interaction) {
    return $this->addObject($interaction);
  }

  /**
   * {@inheritdoc}
   *
   * @return MapInterface
   *   The Map object.
   */
  public function addComponent(ComponentInterface $component) {
    return $this->addObject($component);
  }

  /**
   * {@inheritdoc}
   *
   * @return MapInterface
   *   The Map object.
   */
  public function removeLayer($layer_id) {
    $layers = $this->getOption('layers', array());
    unset($layers[$layer_id]);
    return $this->setOption('layers', $layers)->removeObject($layer_id);
  }

  /**
   * {@inheritdoc}
   *
   * @return MapInterface
   *   The Map object.
   */
  public function removeComponent($component_id) {
    $components = $this->getOption('components', array());
    unset($components[$component_id]);
    return $this->setOption('components', $components)
      ->removeObject($component_id);
  }

  /**
   * {@inheritdoc}
   *
   * @return MapInterface
   *   The Map object.
   */
  public function removeControl($control_id) {
    $controls = $this->getOption('controls', array());
    unset($controls[$control_id]);
    return $this->setOption('controls', $controls)->removeObject($control_id);
  }

  /**
   * {@inheritdoc}
   *
   * @return MapInterface
   *   The Map object.
   */
  public function removeInteraction($interaction_id) {
    $interactions = $this->getOption('interactions', array());
    unset($interactions[$interaction_id]);
    return $this->setOption('interactions', $interactions)
      ->removeObject($interaction_id);
  }

  /**
   * {@inheritdoc}
   */
  public function attached() {
    $attached = parent::attached();

    $settings = $this->getCollection()->getJS();
    $settings['map'] = array_shift($settings['map']);

    $attached['js'][] = array(
      'data' => array(
        'openlayers' => array(
          'maps' => array(
            $this->getId() => $settings,
          ),
        ),
      ),
      'type' => 'setting',
    );

    return $attached;
  }

  /**
   * {@inheritdoc}
   */
  public function getId() {
    if (!isset($this->id)) {
      $css_map_name = drupal_clean_css_identifier($this->getMachineName());
      // Use uniqid to ensure we've really an unique id - otherwise there will
      // occur issues with caching.
      $this->id = drupal_html_id('openlayers-map-' . $css_map_name . '-' . uniqid('', TRUE));
    }

    return $this->id;
  }

  /**
   * {@inheritdoc}
   */
  public function setId($id) {
    $this->id = drupal_html_id(drupal_clean_css_identifier($id));
  }

  /**
   * {@inheritdoc}
   */
  public function getJS() {
    $js = parent::getJS();
    unset($js['opt']['capabilities']);
    return $js;
  }

  /**
   * {@inheritdoc}
   */
  public function render() {
    $build = $this->build();
    return drupal_render($build);
  }

  /**
   * {@inheritdoc}
   */
  public function build(array $build = array()) {
    $map = $this;

    // If this is an asynchronous map flag it as such.
    if ($asynchronous = $this->isAsynchronous()) {
      $map->setOption('async', $asynchronous);
    }

    if (!$map->getOption('target', FALSE)) {
      $this->setOption('target', $this->getId());
    }

    // Transform the options into objects.
    $map->getCollection()->import($map->optionsToObjects());

    // Run prebuild hook to all objects who implements it.
    $map->preBuild($build, $map);

    $styles = array(
      'width' => $map->getOption('width'),
      'height' => $map->getOption('height'),
    );

    $styles = implode(array_map(function ($key, $value) {
      return $key . ':' . $value . ';';
    }, array_keys($styles), $styles));

    // If this is an asynchronous map flag it as such.
    if ($asynchronous = $this->isAsynchronous()) {
      $this->setOption('async', $asynchronous);
    }

    $capabilities = array();
    if ((bool) $this->getOption('capabilities', FALSE) === TRUE) {
      $items = array_values($this->getOption(array(
        'capabilities',
        'options',
        'table',
      ), array()));
      array_walk($items, 'check_plain');

      $capabilities = array(
        '#weight' => 1,
        '#type' => $this->getOption(array(
          'capabilities',
          'options',
          'container_type',
        ), 'fieldset'),
        '#title' => $this->getOption(array(
          'capabilities',
          'options',
          'title',
        ), NULL),
        '#description' => $this->getOption(array(
          'capabilities',
          'options',
          'description',
        ), NULL),
        '#collapsible' => $this->getOption(array(
          'capabilities',
          'options',
          'collapsible',
        ), TRUE),
        '#collapsed' => $this->getOption(array(
          'capabilities',
          'options',
          'collapsed',
        ), TRUE),
        'description' => array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array(
              'description',
            ),
          ),
          array(
            '#markup' => theme(
              'item_list',
              array(
                'items' => $items,
                'title' => '',
                'type' => 'ul',
              )
            ),
          ),
        ),
      );
    }

    $build = array(
      '#theme' => 'openlayers',
      '#map' => $map,
      'openlayers' => array(
        '#type' => 'container',
        '#attributes' => array(
          'id' => 'openlayers-container-' . $map->getId(),
          'class' => array(
            'contextual-links-region',
            'openlayers-container',
          ),
        ),
        'map-container' => array(
          '#type' => 'container',
          '#attributes' => array(
            'id' => 'map-container-' . $map->getId(),
            'style' => $styles,
            'class' => array(
              'openlayers-map-container',
              ((bool) $asynchronous) ? 'asynchronous' : NULL,
            ),
          ),
          'map' => array(
            '#type' => 'container',
            '#attributes' => array(
              'id' => $map->getId(),
              'class' => array(
                'openlayers-map',
                $map->getMachineName(),
              ),
            ),
          ),
        ),
        '#attached' => $map->getCollection()->getAttached(),
      ),
      'description' => array(
        '#theme' => 'form_element',
        '#description' => $map->getDescription(),
      ),
      'capabilities' => $capabilities,
    );

    $map->postBuild($build, $map);

    return $build;
  }

  /**
   * {@inheritdoc}
   */
  public function optionsToObjects() {
    $import = array();

    // TODO: Simplify this.
    // Add the objects from the configuration.
    foreach (Openlayers::getPluginTypes(array('map')) as $weight_type => $type) {
      foreach ($this->getOption($type . 's', array()) as $weight => $object) {
        if (!$this->getCollection()->getObjectById($type, $object)) {
          if ($merge_object = Openlayers::load($type, $object)) {
            $merge_object->setWeight($weight_type . '.' . $weight);
            $import[$type . '_' . $merge_object->getMachineName()] = $merge_object;
          }
        }
      }
    }

    foreach ($this->getCollection()->getFlatList() as $object) {
      $import[$object->getType() . '_' . $object->getMachineName()] = $object;
    }

    return $import;
  }

  /**
   * {@inheritdoc}
   */
  public function setSize(array $size = array()) {
    list($width, $height) = $size;
    $this->setOption('width', $width);
    $this->setOption('height', $height);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getSize() {
    return array($this->getOption('width'), $this->getOption('height'));
  }

  /**
   * {@inheritdoc}
   */
  public function setTarget($target) {
    return $this->setOption('target', $target);
  }

  /**
   * {@inheritdoc}
   */
  public function getTarget() {
    return $this->getOption('target');
  }

  /**
   * {@inheritdoc}
   */
  public function isAsynchronous() {
    return array_reduce($this->getDependencies(), function($res, $obj) {
      return $res + (int) $obj->isAsynchronous();
    }, 0);
  }
}
