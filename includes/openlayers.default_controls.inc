<?php
/**
 * @file
 * Provide default controls.
 */

/**
 * Implements hook_default_controls().
 */
function openlayers_default_controls() {
  $export = array();

  $ol_control = new stdClass();
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'control_attribution';
  $ol_control->name = 'Attribution';
  $ol_control->description = 'Attribution control description';
  $ol_control->class = '\\Drupal\\openlayers\\control\\attribution';
  $ol_control->options = array(
    'collapsible' => 1,
  );
  $export['control_attribution'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'control_fullscreen';
  $ol_control->name = 'Fullscreen';
  $ol_control->description = 'Fullscreen control description';
  $ol_control->class = '\\Drupal\\openlayers\\control\\fullscreen';
  $ol_control->options = array();
  $export['control_fullscreen'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'control_mouseposition';
  $ol_control->name = 'Mouse position';
  $ol_control->description = 'Mouse position control description';
  $ol_control->class = '\\Drupal\\openlayers\\control\\mouseposition';
  $ol_control->options = array();
  $export['control_mouseposition'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'control_rotate';
  $ol_control->name = 'Rotate';
  $ol_control->description = 'Rotate control description';
  $ol_control->class = '\\Drupal\\openlayers\\control\\rotate';
  $ol_control->options = array();
  $export['control_rotate'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'control_scaleline';
  $ol_control->name = 'Scaleline';
  $ol_control->description = 'Scaleline control description';
  $ol_control->class = '\\Drupal\\openlayers\\control\\scaleline';
  $ol_control->options = array();
  $export['control_scaleline'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'control_zoom';
  $ol_control->name = 'Zoom';
  $ol_control->description = 'Zoom control description';
  $ol_control->class = '\\Drupal\\openlayers\\control\\zoom';
  $ol_control->options = array();
  $export['control_zoom'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'control_zoomslider';
  $ol_control->name = 'Zoom slider';
  $ol_control->description = 'Zoom slider control description';
  $ol_control->class = '\\Drupal\\openlayers\\control\\zoomslider';
  $ol_control->options = array();
  $export['control_zoomslider'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'control_zoomtoextent';
  $ol_control->name = 'Zoom to extent';
  $ol_control->description = 'Zoom to extent control description';
  $ol_control->class = '\\Drupal\\openlayers\\control\\zoomtoextent';
  $ol_control->options = array();
  $export['control_zoomtoextent'] = $ol_control;

  return $export;
}
