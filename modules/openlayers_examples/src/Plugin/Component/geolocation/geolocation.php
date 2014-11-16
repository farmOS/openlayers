<?php

namespace Drupal\openlayers\Component;
use Drupal\openlayers\Component;

/**
 * Class openlayers_examples__component__geolocation.
 */
class geolocation extends Component {

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    $form['options']['checkboxID'] = array(
      '#type' => 'textfield',
      '#title' => t('Checkbox HTML ID'),
      '#default_value' => $this->getOption('checkboxID', 'trackPosition'),
    );
    $form['options']['positionAccuracyID'] = array(
      '#type' => 'textfield',
      '#title' => t('Position accuracy HTML ID'),
      '#default_value' => $this->getOption('positionAccuracyID', 'positionAccuracy'),
    );
    $form['options']['altitudeID'] = array(
      '#type' => 'textfield',
      '#title' => t('Altitude HTML ID'),
      '#default_value' => $this->getOption('altitudeID', 'altitude'),
    );
    $form['options']['altitudeAccuracyID'] = array(
      '#type' => 'textfield',
      '#title' => t('Altitude accuracy HTML ID'),
      '#default_value' => $this->getOption('altitudeAccuracyID', 'altitudeAccuracy'),
    );
    $form['options']['headingID'] = array(
      '#type' => 'textfield',
      '#title' => t('Heading HTML ID'),
      '#default_value' => $this->getOption('headingID', 'heading'),
    );
    $form['options']['speedID'] = array(
      '#type' => 'textfield',
      '#title' => t('Speed HTML ID'),
      '#default_value' => $this->getOption('speedID', 'speed'),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function alterBuild(&$build, $map) {
    $build['component'] = array(
      '#type' => 'fieldset',
      '#title' => 'Example Geolocation component',
    );

    $build['component']['info'] = array(
      '#markup' => '<div id="info"></div>',
    );

    $build['component']['trackPosition'] = array(
      '#type' => 'checkbox',
      '#title' => 'Track position',
      '#attributes' => array(
        'id' => 'trackPosition',
      ),
    );

    $build['component']['positionAccuracy'] = array(
      '#type' => 'textfield',
      '#title' => 'Position accuracy',
      '#attributes' => array(
        'id' => 'positionAccuracy',
      ),
    );

    $build['component']['altitude'] = array(
      '#type' => 'textfield',
      '#title' => 'Altitude',
      '#attributes' => array(
        'id' => 'altitude',
      ),
    );

    $build['component']['altitudeAccuracy'] = array(
      '#type' => 'textfield',
      '#title' => 'Altitude accuracy',
      '#attributes' => array(
        'id' => 'altitudeAccuracy',
      ),
    );

    $build['component']['heading'] = array(
      '#type' => 'textfield',
      '#title' => 'Heading',
      '#attributes' => array(
        'id' => 'heading',
      ),
    );

    $build['component']['speed'] = array(
      '#type' => 'textfield',
      '#title' => 'Speed',
      '#attributes' => array(
        'id' => 'speed',
      ),
    );

    $build['map']['#attributes']['style'] = $build['#attributes']['style'];
    unset($build['#attributes']['style']);
  }

}
