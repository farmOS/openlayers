<?php
/**
 * @file
 * Source: Field.
 */

namespace Drupal\openlayers_field\Plugin\Source\Field;

use Drupal\geocoder\Geocoder;
use Drupal\openlayers\Plugin\Source\Vector\Vector;

/**
 * Class Field.
 *
 * @OpenlayersPlugin(
 *  id = "Field",
 *  description = "Provides a source where data are geocoded from provided options."
 * )
 */
class Field extends Vector {
  /**
   * {@inheritdoc}
   */
  public function dependencies() {
    return array('geocoder');
  }

  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {

    $geocoder_plugins = (array) $this->getOption('geocoder_handlers', array('GoogleMaps'));
    $plugins = array_combine(array_values(\Drupal\geocoder\Geocoder::getProviderPlugins()), array_values(\Drupal\geocoder\Geocoder::getProviderPlugins()));
    $plugins_array = array();

    $i = 0;
    foreach ($plugins as $plugin) {
      $plugins_array[$plugin] = array(
        'name' => $plugin,
        'weight' => $i++,
        'enabled' => 0,
      );
    }

    $i = 0;
    foreach($geocoder_plugins as $name => $option) {
      if (is_array($option)) {
        if ($option['enabled'] == 1) {
          $plugins_array[$name]['enabled'] = 1;
          $plugins_array[$name]['weight'] = isset($option['weight']) ? $option['weight'] : $i++;
        }
      } else {
        if ($plugins[$option]) {
          $plugins_array[$option]['enabled'] = 1;
          $plugins_array[$option]['weight'] = $i++;
        }
      }
    }

    uasort($plugins_array, function($a, $b) {
      if ($a['enabled'] > $b['enabled']) {
        return -1;
      }
      elseif ($a['enabled'] < $b['enabled']) {
        return 1;
      }
      if ($a['weight'] < $b['weight']) {
        return -1;
      }
      elseif ($a['weight'] > $b['weight']) {
        return 1;
      }
      if ($a['name'] < $b['name']) {
        return -1;
      }
      elseif ($a['name'] > $b['name']) {
        return 1;
      }
      return 0;
    });

    $data = array();
    foreach ($plugins_array as $plugin) {
      $data[$plugin['name']] = array(
        'name' => $plugin['name'],
        'machine_name' => $plugin['name'],
        'weight' => $plugin['weight'],
        'enabled' => $plugin['enabled'],
      );
    }

    $rows = array();
    $row_elements = array();
    foreach ($data as $id => $entry) {
      $rows[$id] = array(
        'data' => array(
          array(
            'class',
            array(
              'entry-cross',
            ),
          ),
          array(
            'data' => array(
              '#type' => 'weight',
              '#title' => t('Weight'),
              '#title_display' => 'invisible',
              '#default_value' => $entry['weight'],
              '#parents' => array('options', 'geocoder_handlers', $id, 'weight'),
              '#attributes' => array(
                'class' => array('entry-order-weight'),
              ),
            ),
          ),
          array(
            'data' => array(
              '#type' => 'checkbox',
              '#title' => t('Enable'),
              '#title_display' => 'invisible',
              '#default_value' => (bool) $entry['enabled'],
              '#parents' => array('options', 'geocoder_handlers', $id, 'enabled'),
            ),
          ),
          check_plain($entry['name']),
        ),
        'class' => array('draggable'),
      );
      // Build rows of the form elements in the table.
      $row_elements[$id] = array(
        'weight' => &$rows[$id]['data'][1]['data'],
        'enabled' => &$rows[$id]['data'][2]['data'],
      );
    }

    // Add the table to the form.
    $form['options']['geocoder_handlers'] = array(
      '#theme' => 'table',
      '#caption' => t('Select the geocoder plugin in use, from the top to the bottom.'),
      // The row form elements need to be processed and build,
      // therefore pass them as element children.
      'elements' => $row_elements,
      '#header' => array(
        // We need two empty columns for the weigth field and the cross.
        array('data' => NULL, 'colspan' => 2),
        t('Enabled'),
        t('Name'),
      ),
      '#rows' => $rows,
      '#empty' => t('There are no entries available.'),
      '#attributes' => array('id' => 'entry-order-geocoder-handlers'),
    );
    drupal_add_tabledrag('entry-order-geocoder-handlers', 'order', 'sibling', 'entry-order-weight');

    $fields = $this->getOption('fields', array(array()));
    if (!empty($fields[0])) {
      $fields[] = array();
    }

    if (empty($fields)) {
      $fields[] = array();
    }

    foreach ($fields as $index => $field) {
      $form['options']['fields'][$index] = array(
        '#type' => 'fieldset',
        '#title' => ($field == end($fields)) ? t('Add a new feature') : 'Feature ' . $index,
        '#collapsible' => TRUE,
        '#collapsed' => ($field == end($fields)) ? TRUE : FALSE,
        'title' => array(
          '#title' => 'Title',
          '#type' => 'textfield',
          '#default_value' => isset($fields[$index]['title']) ? $fields[$index]['title'] : '',
        ),
        'description' => array(
          '#title' => 'Description',
          '#type' => 'textarea',
          '#default_value' => isset($fields[$index]['description']) ? $fields[$index]['description'] : '',
        ),
        'address' => array(
          '#title' => 'Address',
          '#type' => 'textfield',
          '#default_value' => isset($fields[$index]['address']) ? $fields[$index]['address'] : '',
        ),
        'geojson' => array(
          '#type' => 'textarea',
          '#title' => 'GeoJson',
          '#disabled' => TRUE,
          '#default_value' => isset($fields[$index]['geojson']) ? $fields[$index]['geojson'] : '',
        ),
      );
    }
  }

  /**
   * {@inheritdoc}
   */
  public function optionsFormSubmit(array $form, array &$form_state) {
    $fields = $form_state['values']['options']['fields'];

    $geocoder_handlers = array();
    foreach ($form_state['values']['options']['geocoder_handlers'] as $plugin_id => $plugin) {
      if ($plugin['enabled']) {
        $geocoder_handlers[] = $plugin_id;
      }
    }

    // This is for optimizing the source rendering in JS.
    // It converts all the address fields of the source to WKT.
    foreach ($fields as $index => &$field) {
      if (isset($field['address']) && !empty($field['address'])) {
        if ($addressCollection = Geocoder::geocode($geocoder_handlers, $field['address'])) {
          $dumper = \Drupal::service('geocoder.Dumper')->createInstance('geojson');
          $geojson = $dumper->dump($addressCollection->first());
          $feature = json_decode($geojson, TRUE);

          if (isset($field['title']) && !empty($field['title'])) {
            $feature['properties']['name'] = $field['title'];
          }
          if (isset($field['description']) && !empty($field['description'])) {
            $feature['properties']['description'] = $field['description'];
          }

          $field['geojson'] = json_encode($feature);
        }
        else {
          unset($field['geojson']);
        }
      }
      else {
        unset($fields[$index]);
      }
    }

    $form_state['values']['options']['fields'] = $fields;

    parent::optionsFormSubmit($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function getJS() {
    $js = parent::getJS();
    $features = $this->getGeojsonFeatures();

    if (!empty($features)) {
      $js['opt']['geojson_data'] = array(
        'type' => 'FeatureCollection',
        'features' => $features,
      );
    }

    unset($js['opt']['fields']);
    return $js;
  }

  /**
   * Compute the GeoJSON features array.
   *
   * @return array
   *   The geojson array.
   */
  protected function getGeojsonFeatures() {
    $features = array();

    foreach ($this->getOption('fields', array()) as $field) {
      $feature = FALSE;

      if (isset($field['geojson']) && !empty($field['geojson'])) {
        $feature = json_decode($field['geojson'], TRUE);

        if (isset($field['title']) && !empty($field['title'])) {
          $feature['properties']['name'] = $field['title'];
        }

        if (isset($field['description']) && !empty($field['description'])) {
          $feature['properties']['description'] = $field['description'];
        }
      }
      else {
        if (isset($field['address']) && !empty($field['address'])) {

          $geocoder_handlers = array();
          foreach ($this->getOption('geocoder_handlers', 'GoogleMaps') as $plugin_id => $plugin) {
            if ($plugin['enabled']) {
              $geocoder_handlers[] = $plugin_id;
            }
          }

          if ($addressCollection = Geocoder::geocode($geocoder_handlers, $field['address'])) {
            $dumper = \Drupal::service('geocoder.Dumper')->createInstance('geojson');
            $geojson = $dumper->dump($addressCollection->first());
            $feature = json_decode($geojson, TRUE);

            if (isset($field['title']) && !empty($field['title'])) {
              $feature['properties']['name'] = $field['title'];
            }
            if (isset($field['description']) && !empty($field['description'])) {
              $feature['properties']['description'] = $field['description'];
            }
          }
        }
      }

      if ($feature) {
        $features[] = $feature;
      }
    }

    return $features;
  }

}
