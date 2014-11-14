<?php
/**
 * @file
 * Class openlayers_object.
 */

namespace Drupal\openlayers;

/**
 * Class openlayers_object.
 */
abstract class Object implements ObjectInterface {

  /**
   * @var string
   */
  public $machine_name;

  /**
   * @var string
   */
  private $name;

  /**
   * @var string
   */
  private $description;

  /**
   * @var string
   */
  public $class;

  /**
   * @var array
   */
  public $options = array();

  /**
   * The plugin array.
   * @var array
   */
  private $plugin = NULL;

  /**
   * @var array
   */
  protected $attached = array(
    'js' => array(),
    'css' => array(),
    'library' => array(),
    'libraries_load' => array(),
  );

  /**
   * {@inheritdoc}
   */
  public function default_properties() {
    return array(
      'machine_name' => '',
      'name' => '',
      'description' => '',
      'options' => array(),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function init(array $data) {
    // Mash the provided configuration with the defaults.
    foreach ($this->default_properties() as $property => $value) {
      if (isset($data[$property])) {
        $this->{$property} = $data[$property];
      }
    }

    // If there are options ensure the provided ones overwrite the defaults.
    if (isset($data['options'])) {
      $this->options = array_replace_recursive((array) $this->options, (array) $data['options']);
    }

    $this->class = get_class($this);
    $this->plugin = ctools_get_plugins('openlayers', $this->getType(), get_class($this));

    // We need to ensure the object has a proper machine name.
    if (empty($this->machine_name)) {
      $this->machine_name = drupal_html_id($this->getType() . '-' . time());
    }
  }

  /**
   * {@inheritdoc}
   *
   * @TODO What is this return? If it is the form, why is form by reference?
   */
  public function options_form(&$form, &$form_state) {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function options_form_validate($form, &$form_state) {}

  /**
   * {@inheritdoc}
   */
  public function options_form_submit($form, &$form_state) {}

  /**
   * Allows to alter the build of a object.
   *
   * @param array $build
   *   The build array by reference.
   * @param openlayers_map_interface $map
   *   The map object this build is related to.
   */
  public function alterBuild(&$build, $map) {}

  /**
   * {@inheritdoc}
   */
  public function getType() {
    list($module, $type) = explode('__', get_class($this));
    if (isset($type)) {
      return $type;
    }
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function develop() {}

  /**
   * {@inheritdoc}
   */
  public function clearOption($parents) {
    $ref = &$this->options;

    if (is_string($parents)) {
      $parents = array($parents);
    }

    $last = end($parents);
    reset($parents);
    foreach ($parents as $parent) {
      if (isset($ref) && !is_array($ref)) {
        $ref = array();
      }
      if ($last == $parent) {
        unset($ref[$parent]);
      }
      else {
        if (isset($ref[$parent])) {
          $ref = &$ref[$parent];
        }
        else {
          break;
        }
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function setOption($parents, $value = NULL) {
    $ref = &$this->options;

    if (is_string($parents)) {
      $parents = array($parents);
    }

    foreach ($parents as $parent) {
      if (isset($ref) && !is_array($ref)) {
        $ref = array();
      }
      $ref = &$ref[$parent];
    }
    $ref = $value;
  }

  /**
   * Getter allows access to any property no mather what scope it has.
   *
   * @TODO is this a good idea? Why not __get()?
   *
   * @param string $prop
   *   Property to get.
   *
   * @return mixed
   *   The value of the property.
   */
  public function get($prop) {
    return $this->$prop;
  }

  /**
   * {@inheritdoc}
   */
  public function getOption($parents, $default_value = NULL) {
    $options = $this->options;

    if (is_string($parents)) {
      $parents = array($parents);
    }

    if (is_array($parents)) {
      $notfound = FALSE;
      foreach ($parents as $parent) {
        if (isset($options[$parent])) {
          $options = $options[$parent];
        }
        else {
          $notfound = TRUE;
          break;
        }
      }
      if (!$notfound) {
        return $options;
      }
    }

    if (is_null($default_value)) {
      return FALSE;
    }

    return $default_value;
  }

  /**
   * {@inheritdoc}
   */
  public function attached() {
    if ($plugin = $this->getPlugin()) {
      // Attach JS / CSS files named like the class automatically.
      $file = $plugin['path'] . '/' . get_class($this) . '.js';
      if (file_exists($file)) {
        $this->attached['js'][$file] = array(
          'data' => $file,
          'type' => 'file',
          'group' => openlayers_config::JS_GROUP,
          'weight' => openlayers_config::JS_WEIGHT,
        );
      }
      $file = $plugin['path'] . '/' . get_class($this) . '.css';
      if (file_exists($file)) {
        $this->attached['css'][$file] = array(
          'data' => $file,
          'type' => 'file',
          'group' => openlayers_config::JS_GROUP,
          'weight' => openlayers_config::JS_WEIGHT,
        );
      }
    }

    return $this->attached;
  }

  /**
   * {@inheritdoc}
   */
  public function dependencies() {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function getPlugin() {
    return $this->plugin;
  }

  /**
   * {@inheritdoc}
   */
  public function toJSArray() {
    // TODO: find a better solution here.
    return json_decode(json_encode($this), TRUE);
  }

}
