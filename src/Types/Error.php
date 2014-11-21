<?php
/**
 * @file
 * Class openlayers_config.
 */

namespace Drupal\openlayers\Types;

/**
 * Class openlayers_config.
 *
 * Dummy class to avoid breaking the whole processing if a plugin class is
 * missing.
 */
class Error extends Object {

  /**
   * @var string
   */
  public $errorMessage;

  /**
   * {@inheritdoc}
   */
  public function __construct() {
    foreach ($this->defaultProperties() as $property => $value) {
      $this->{$property} = $value;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function defaultProperties() {
    $properties = parent::defaultProperties();
    $properties['errorMessage'] = 'Error while loading object @machine_name having class @class.';
    return $properties;
  }

  /**
   * {@inheritdoc}
   */
  public function init(array $data) {
    foreach ($this->defaultProperties() as $property => $value) {
      if (isset($data[$property])) {
        $this->{$property} = $data[$property];
      }
    }

    if (isset($data['options'])) {
      $this->options = array_replace_recursive((array) $this->options, (array) $data['options']);
    }

    watchdog(\Drupal\openlayers\Config::WATCHDOG_TYPE, $this->getMessage(), array(), WATCHDOG_ERROR);
    drupal_set_message($this->getMessage(), 'error', FALSE);
  }

  /**
   * {@inheritdoc}
   */
  public function getMessage() {
    $machine_name = isset($this->machine_name) ? $this->machine_name : 'undefined';
    $class = isset($this->class) ? $this->class : 'undefined';
    $type = isset($this->type) ? $this->type : 'undefined';

    return t($this->errorMessage, array(
      '@machine_name' => $machine_name,
      '@class' => $class,
      '@type' => $type,
    ));
  }

  /**
   * {@inheritdoc}
   */
  public function getSource() {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function getSources() {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function getLayers() {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function getControls() {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function getInteractions() {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function getComponents() {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function getType() {
    return 'Error';
  }
}
