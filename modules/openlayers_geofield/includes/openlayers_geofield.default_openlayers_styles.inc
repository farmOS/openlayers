<?php
/**
 * @file
 * Provide default styles.
 */

/**
 * Implements hook_default_openlayers_styles().
 */
function openlayers_geofield_default_openlayers_styles() {
  $export = array();

  $ol_style = new stdClass();
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_geofield_style_edit';
  $ol_style->name = 'Openlayers Geofield edit style';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:Circle';
  $ol_style->options = array(
    'fill' => array(
      'color' => '100, 100, 100, 0.90',
    ),
    'stroke' => array(
      'color' => '0, 0, 0, 1',
      'width' => 3,
      'lineDash' => '5,15',
    ),
    'radius' => 5,
  );
  $export['openlayers_geofield_style_edit'] = $ol_style;

  return $export;
}
