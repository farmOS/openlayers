<?php
/**
 * @file
 * Provide default styles.
 */

/**
 * Implements hook_default_openlayers_styles().
 */
function openlayers_default_openlayers_styles() {
  $export = array();

  $ol_style = new stdClass();
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_style_default';
  $ol_style->name = 'Openlayers default style';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:Circle';
  $ol_style->options = array(
    'fill' => array(
      'color' => '255, 255, 255, 0.4',
    ),
    'stroke' => array(
      'color' => '51, 153, 204, 1',
      'width' => 1.25,
    ),
    'radius' => 5,
  );
  $export['openlayers_style_default'] = $ol_style;

  $ol_style = new stdClass();
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_style_invisible';
  $ol_style->name = 'Openlayers style invisible';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:Invisible';
  $export['openlayers_style_invisible'] = $ol_style;

  return $export;
}
