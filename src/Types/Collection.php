<?php
/**
 * @file
 * Class openlayers_object.
 */

namespace Drupal\openlayers\Types;

/**
 * Class Collection.
 */
class Collection {

  protected $objects = array();

  public function append(\Drupal\openlayers\Types\Object $object) {
    $type = strtolower(implode('', array_slice(explode('.', $object->factory_service), -3, 1)));
    $this->objects[$type][$object->machine_name] = $object;
  }

  public function getAttached() {
    $attached = array();
    foreach($this->objects as $objects) {
      foreach($objects as $object) {
        $object_attached = $object->attached() + array('js' => array(), 'css' => array(), 'libraries_load' => array());
        foreach(array('js', 'css', 'libraries_load') as $type) {
          foreach($object_attached[$type] as $data) {
            $attached[$type][] = $data;
          }
        }
      }
    }
    return $attached;
  }

  public function getJS() {
    $clone = clone $this;
    $settings = array();
    foreach($clone->objects as $type => $objects) {
      foreach($objects as $object) {
        $settings[$type][] = $object->getJS();
      }
    }

    $settings = array_map_recursive('_floatval_if_numeric', $settings);
    $settings = removeEmptyElements($settings);

    return $settings;
  }

  public function getObjects($type = NULL) {
    if ($type != null && isset($this->objects[$type])) {
      return $this->objects[$type];
    }
    return $this->objects;
  }

  public function getFlatList($type = NULL) {
    $list = array();

    if ($type != null && isset($this->objects[$type])) {
      foreach ($this->objects[$type] as $object) {
        $list[] = $object;
      }
    } else {
      foreach ($this->objects as $objects) {
        foreach ($objects as $object) {
          $list[] = $object;
        }
      }
    }

    return $list;
  }

  public function merge(Collection $collection) {
    foreach($collection->getObjects() as $objects) {
      foreach($objects as $object) {
        $this->append($object);
      }
    }
  }
}
