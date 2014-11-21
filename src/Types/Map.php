<?php
/**
 * @file
 * Class openlayers_map.
 */

namespace Drupal\openlayers\Types;

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
  public function attached(\Drupal\openlayers\Types\ObjectInterface $context) {
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

  /**
   * {@inheritdoc}
   */
  public function preBuild(array &$build, \Drupal\openlayers\Types\ObjectInterface $context = NULL) {
    parent::preBuild($build, $context);

    foreach (openlayers_object_types() as $type) {
      if (isset($this->objects[$type])) {
        foreach ($this->objects[$type] as $object) {
          $object->preBuild($build, $this);
          drupal_alter('openlayers_object_preprocess', $object, $this);
        }
      }
    }
    drupal_alter('openlayers_object_preprocess', $this);
  }


  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, \Drupal\openlayers\Types\ObjectInterface $context = NULL) {
    parent::postBuild($build, $context);

    foreach (openlayers_object_types() as $type) {
      if (isset($this->objects[$type])) {
        foreach ($this->objects[$type] as $object) {
          $object->postBuild($build, $context);
          drupal_alter('openlayers_object_postprocess', $object, $build);
        }
      }
    }
    drupal_alter('openlayers_object_postprocess', $this, $build);
  }

  /**
   * {@inheritdoc}
   */
  public function build() {
    $map = $this;
    $build = array();

    $current_path = current_path();
    if ('system/ajax' == $current_path) {
      $current_path = $_SESSION['current_path'];
    }

    $map->preBuild($build, $map);

    $attached = $map->attached($map);
    $objects = $map->getObjects();
    $objects['map'] = $map;

    $setting = array(
      'openlayers' => array(
        'maps' => array(
          $map->getId() => $map->getJSObjects(),
        ),
      ),
    );

    $links = array(
      'openlayers' => array(
        'title' => 'Edit this map',
        'href' => 'admin/structure/openlayers/maps/list/' . $map->machine_name . '/edit',
        'query' => array(
          'destination' => $current_path,
        ),
      ),
    );
    $asynchronous = 0;
    foreach (openlayers_object_types() as $type) {
      // Build contextual link title for this type.
      $links[$type] = array(
        'title' => '<strong>' . ucwords($type . 's') . '</strong>',
        'html' => TRUE,
      );
      foreach ($objects[$type] as $object) {
        $asynchronous += (int) $object->isAsynchronous();

        // Build contextual link for this object.
        $name = $object->get('name');
        if (empty($name)) {
          $name = $object->machine_name;
        }
        $links[$type . ':' . $object->machine_name] = array(
          'title' => t('Edit @object_name', array('@object_name' => $name)),
          'href' => 'admin/structure/openlayers/' . $type . 's/list/' . $object->machine_name . '/edit',
          'query' => array(
            'destination' => $current_path,
          ),
        );
      }
    }
    // If this is asynchronous flag it as such.
    if ($asynchronous) {
      $setting['openlayers']['maps'][$map->getId()]['map']['async'] = $asynchronous;
    }

    $attached['js'][] = array(
      'data' => $setting,
      'type' => 'setting',
    );


    $styles = array(
      'width' => $map->getOption('width'),
      'height' => $map->getOption('height'),
    );

    $css_styles = '';
    foreach ($styles as $property => $value) {
      $css_styles .= $property . ':' . $value . ';';
    }

    $build += array(
      '#type' => 'container',
      'contextual_links' => array(
        '#prefix' => '<div class="contextual-links-wrapper">',
        '#suffix' => '</div>',
        '#theme' => 'links__contextual',
        '#links' => $links,
        '#attributes' => array('class' => array('contextual-links')),
        '#attached' => array(
          'library' => array(array('contextual', 'contextual-links')),
        ),
      ),
      '#attributes' => array(
        'id' => 'openlayers-container-' . $map->getId(),
        'style' => $css_styles,
        'class' => array(
          'contextual-links-region',
          'openlayers-container',
        ),
      ),
      'map' => array(
        '#theme' => 'html_tag',
        '#tag' => 'div',
        '#value' => '',
        '#attributes' => array(
          'id' => $map->getId(),
          'class' => array(
            'openlayers-map',
            $map->machine_name,
          ),
        ),
        '#attached' => array(
          'library' => $attached['library'],
          'libraries_load' => $attached['libraries_load'],
          'js' => $attached['js'],
          'css' => $attached['css'],
        ),
      ),
    );

    // If this is an asynchronous map flag it as such.
    if ($asynchronous) {
      $build['map']['#attributes']['class'][] = 'asynchronous';
    }

    if ($map->getOption('contextualLinks') == FALSE) {
      unset($build['contextual_links']);
    }

    $map->postBuild($build, $map);

    return $build;
  }

}
