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

  function parse_classname() {
    $name = get_class($this);
    return array(
      'namespace' => array_slice(explode('\\', $name), 0, -1),
      'classname' => join('', array_slice(explode('\\', $name), -1)),
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

    $class_info = $this->parse_classname();
    $this->class = get_class($this);
    $this->plugin = ctools_get_plugins('openlayers', $this->getType(), $class_info['classname']);

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

  public function preBuild(array &$build, \Drupal\openlayers\ObjectInterface $context = null) {}

  public function postBuild(array &$build, \Drupal\openlayers\ObjectInterface $context = null) {}

  public function build() {}

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
  public function attached(\Drupal\openlayers\ObjectInterface $context) {
    if ($plugin = $this->getPlugin()) {
      $jsdir = $plugin['path'] . '/js';
      $cssdir = $plugin['path'] . '/css';
      if (file_exists($jsdir)) {
        foreach(file_scan_directory($jsdir, '/.*\.js$/') as $file) {
          $this->attached['js'][$file->uri] = array(
            'data' => $file->uri,
            'type' => 'file',
            'group' => Config::JS_GROUP,
            'weight' => Config::JS_WEIGHT,
          );
        }
      }
      if (file_exists($cssdir)) {
        foreach(file_scan_directory($cssdir, '/.*\.css$/') as $file) {
          $this->attached['css'][$file->uri] = array(
            'data' => $file->uri,
            'type' => 'file',
            'group' => Config::JS_GROUP,
            'weight' => Config::JS_WEIGHT,
          );
        }
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

  /**
   * {@inheritdoc}
   */
  public function isAsynchronous() {
    return FALSE;
  }
}
