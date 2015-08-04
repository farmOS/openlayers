<?php
/**
 * @file
 * Component: Geofield.
 */

namespace Drupal\openlayers_geofield\Plugin\Component\Geofield;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Component;
use Drupal\openlayers\Types\ObjectInterface;
use \geoPHP;

/**
 * Class Geofield.
 *
 * @OpenlayersPlugin(
 *  id = "Geofield"
 * )
 */
class Geofield extends Component {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['dataType'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Data type'),
      '#description' => t('If more than one type is choosen a control to select the type to use is displayed when drawing.'),
      '#multiple' => TRUE,
      '#options' => array(
        'GeoJSON' => 'GeoJSON',
        'KML' => 'KML',
        'GPX' => 'GPX',
        'WKT' => 'WKT',
      ),
      '#default_value' => $this->getOption('dataType'),
      '#required' => TRUE,
    );
    $form['options']['dataProjection'] = array(
      '#type' => 'radios',
      '#title' => t('Data projection'),
      '#options' => array(
        'EPSG:4326' => 'EPSG:4326',
        'EPSG:3857' => 'EPSG:3857',
      ),
      '#description' => t('Defines in which projection the data are read and written.'),
      '#default_value' => $this->getOption('dataProjection', 'EPSG:4326'),
      '#required' => TRUE,
    );
    $form['options']['featureLimit'] = array(
      '#type' => 'textfield',
      '#title' => t('Feature limit'),
      '#description' => t('Limits the number of features. Set to 0 for no limit.'),
      '#default_value' => $this->getOption('featureLimit'),
      '#required' => TRUE,
    );
    $form['options']['showInputField'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show input field'),
      '#description' => t('Shows the data in a textarea.'),
      '#default_value' => (int) $this->getOption('showInputField'),
    );
    $form['options']['inputFieldName'] = array(
      '#type' => 'textfield',
      '#title' => t('Name of the input field'),
      '#description' => t('Define the name of the input field. You can use brackets to build structure: [geofield][component][data]'),
      '#default_value' => $this->getOption('inputFieldName'),
    );
    $form['options']['initialData'] = array(
      '#type' => 'textarea',
      '#title' => t('Initial data'),
      '#description' => t('Initial data to set. You can use any of the data types available as "Data type". Ensure the data have the same projection as defined in "Data projection".'),
      '#default_value' => $this->getOption('initialData'),
    );
    $form['options']['editStyle'] = array(
      '#type' => 'select',
      '#title' => t('Edit style'),
      '#default_value' => $this->getOption('editStyle'),
      '#options' => Openlayers::loadAllAsOptions('style'),
    );
    $form['options']['editLayer'] = array(
      '#type' => 'select',
      '#title' => t('- Select a layer -'),
      '#default_value' => $this->getOption('editLayer'),
      '#options' => Openlayers::loadAllAsOptions('layer'),
    );
  }

  /**
   * {@inheritDoc}
   */
  public function optionsToObjects() {
    $import = parent::optionsToObjects();

    if ($style = $this->getOption('editStyle')) {
      $style = Openlayers::load('style', $style);

      $this->setWeight($style->getWeight() + 1);
      $import = array_merge($style->getCollection()->getFlatList(), $import);
    }

    if ($layer = $this->getOption('editLayer')) {
      $layer = Openlayers::load('layer', $layer);
      $import = array_merge($import, $layer->getCollection()->getFlatList());
    }

    return $import;
  }

  /**
   * {@inheritdoc}
   */
  public function preBuild(array &$build, ObjectInterface $context = NULL) {
    // Auto-detect the source to use for the features.
    $source = $this->getOption('source');
    if (empty($source)) {
      foreach ($context->getCollection()->getObjects('source') as $source) {
        if ($source instanceof \Drupal\openlayers_geofield\Plugin\Source\Geofield\Geofield) {
          $this->setOption('source', $source->getMachineName());
        }
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getJS() {
    // Ensure the options are properly set and clean.
    $this->setOption('dataType', array_filter($this->getOption('dataType', array('WKT' => 'WKT'))));

    $initial_data = $this->getOption('initialData');

    // Process initial data. Ensure it's WKT.
    if (isset($initial_data)) {

      // Process strings and arrays likewise.
      geophp_load();
      if (!is_array($initial_data)) {
        $initial_data = array($initial_data);
      }
      $geoms = array();
      foreach ($initial_data as $delta => $item) {
        if (is_array($item) && array_key_exists('geom', $item)) {
          $geoms[] = geoPHP::load($item['geom']);
        }
        else {
          // Is this really necessary ? Commented for now.
          // $geoms[] = geoPHP::load('');
        }
      }
      $combined_geom = geoPHP::geometryReduce($geoms);
      // If we could parse the geom process further.
      if ($combined_geom && !$combined_geom->isEmpty()) {
        // We want to force the combined_geom into a geometryCollection.
        $geom_type = $combined_geom->geometryType();
        if ($geom_type == 'MultiPolygon' || $geom_type == 'MultiLineString' || $geom_type == 'MultiPoint') {
          $combined_geom = new \GeometryCollection($combined_geom->getComponents());
        }

        // Ensure proper initial data in the textarea / hidden field.
        $data_type = key($this->getOption('dataType', array('WKT' => 'WKT')));
        $this->setOption('initialData', $combined_geom->out(strtolower($data_type)));
        $this->setOption('initialDataType', $data_type);
      }
      else {
        // Set initial data to NULL if the data couldn't be evaluated.
        $this->setOption('initialData', NULL);
        $this->setOption('initialDataType', key($this->getOption('dataType', array('WKT' => 'WKT'))));
      }
    }
    return parent::getJS();
  }

  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, ObjectInterface $context = NULL) {
    $component = array(
      '#type' => 'fieldset',
      '#title' => 'Geofield component',
      '#attributes' => array(
        'id' => 'geofield-' . $context->getId(),
      ),
    );

    $data_type = $this->getOption('dataType');
    if (count($data_type) > 1) {
      $component['dataType'] = array(
        '#type' => 'select',
        '#title' => 'Data type',
        '#options' => array_intersect_key(
          array(
            'GeoJSON' => 'GeoJSON',
            'KML' => 'KML',
            'GPX' => 'GPX',
            'WKT' => 'WKT',
          ),
          $data_type
        ),
        '#attributes' => array(
          'class' => array('data-type'),
        ),
      );
    }
    else {
      $component['dataType'] = array(
        '#type' => 'hidden',
        '#default_value' => reset($data_type),
        '#value' => reset($data_type),
        '#attributes' => array(
          'class' => array('data-type'),
        ),
      );
    }

    $component['data'] = array(
      '#type' => ($this->getOption('showInputField')) ? 'textarea' : 'hidden',
      '#title' => 'Data',
      '#attributes' => array(
        'class' => array('openlayers-geofield-data'),
      ),
      '#default_value' => $this->getOption('initialData', ''),
      '#value' => $this->getOption('initialData', ''),
    );

    // Now add the component into the build array. This is a bit complex due
    // the fact that we want to support form nesting.
    $parents = array('geofield', 'component');
    $data_input_field_name = $this->getOption('inputFieldName');
    if (!empty($data_input_field_name)) {
      $data_input_field_name = preg_replace('/(^\[|\]$)/', '', $data_input_field_name);
      $levels = explode('][', $data_input_field_name);
      $parents = array_slice(explode('][', $data_input_field_name), 0, count($levels) - 1);
      // Ensure the requested name for the input data field is set.
      $component[end($levels)] = $component['data'];
      unset($component['data']);
    }
    if (!empty($parents)) {
      drupal_array_set_nested_value($build, $parents, $component);
    }
    else {
      $build += $component;
    }
  }
}
