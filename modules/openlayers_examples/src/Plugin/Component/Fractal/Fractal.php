<?php
/**
 * @file
 * Component: Fractal.
 */

namespace Drupal\openlayers_examples\Plugin\Component\Fractal;
use Drupal\Component\Annotation\Plugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Component;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class Fractal.
 *
 * @Plugin(
 *   id = "Fractal"
 * )
 *
 */
class Fractal extends Component {
  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, ObjectInterface $context = NULL) {
    $build = array(
      'map' => $build,
      'Swipe' => array(
        '#type' => 'fieldset',
        '#title' => 'Example Fractal component',
        'info' => array(
          '#markup' => 'This example is based on the <a href="http://openlayers.org/en/master/examples/fractal.html">offical fractal example</a>. You need the <em><a href="https://drupal.org/project/elements">elements</a></em> module to get it working properly.'
        ),
        'swipe' => array(
          '#type' => 'rangefield',
          '#min' => 0,
          '#max' => 9,
          '#step' => 1,
          '#value' => 5,
          '#attributes' => array(
            'id' => 'depth',
            'style' => 'width: 100%;'
          ),
        ),
        'count' => array(
          '#type' => 'container',
          '#prefix' => 'Points: ',
          '#attributes' => array(
            'id' => 'count',
            'style' => 'width: 100%;'
          ),
        ),
      ),
    );
  }
}
