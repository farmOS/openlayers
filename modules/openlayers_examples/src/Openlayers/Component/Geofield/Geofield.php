<?php
/**
 * @file
 * Component: Geofield
 */

namespace Drupal\openlayers\Component;
use Drupal\openlayers\Types\Component;

$plugin = array(
  'class' => '\\Drupal\\openlayers\\Component\\Geofield',
);

/**
 * Class Geofield.
 */
class Geofield extends Component {

  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, \Drupal\openlayers\Types\ObjectInterface $context = NULL) {
    $build = array(
      'map' => $build,
      'Geofield' => array(
        'component' => array(
          '#type' => 'fieldset',
          '#title' => 'Example Geofield component',
          'actionFeature' => array(
            '#type' => 'select',
            '#title' => 'Type of interaction',
            '#options' => array('draw' => 'Draw', 'modify' => 'Modify'),
            '#attributes' => array(
              'id' => 'actionFeature',
            ),
          ),
          'dataType' => array(
            '#type' => 'select',
            '#title' => 'Data type',
            '#options' => array(
              'GeoJSON' => 'GeoJSON',
              'KML' => 'KML',
              'GPX' => 'GPX',
              'WKT' => 'WKT',
            ),
            '#attributes' => array(
              'id' => 'dataType',
            ),
          ),
          'typeOfFeature' => array(
            '#type' => 'select',
            '#title' => 'Geometry type',
            '#options' => array(
              'Point' => 'Point',
              'LineString' => 'LineString',
              'Polygon' => 'Polygon',
            ),
            '#attributes' => array(
              'id' => 'typeOfFeature',
            ),
          ),
          'data' => array(
            '#type' => 'textarea',
            '#title' => 'Data',
            '#attributes' => array(
              'id' => 'data',
            ),
            '#value' => '',
          ),
          'clearmap' => array(
            '#markup' => "<a href='#' id='clearmap'>Clear the map</a>",
          )
        )
      )
    );
  }

}
