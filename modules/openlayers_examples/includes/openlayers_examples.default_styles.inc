<?php
/**
 * @file
 * Default styles.
 */

/**
 * Implements hook_default_styles().
 */
function openlayers_examples_default_styles() {
  $export = array();

  $ol_style = new stdClass();
  $ol_style->disabled = FALSE; /* Edit this to true to make a default style disabled initially */
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_examples_blue_marker';
  $ol_style->name = 'OpenLayers blue marker';
  $ol_style->description = '';
  $ol_style->class = 'openlayers__style__js';
  $ol_style->options = array(
    'javascript' => 'var style = new ol.style.Style({
                        image: new ol.style.Icon(({
                            scale: 1,
                            anchor: [0.5, 1],
                            anchorXUnits: \'fraction\',
                            anchorYUnits: \'fraction\',
                            src: \'/sites/all/modules/openlayers/modules/openlayers_examples/assets/marker-icon.png\'
                        }))
                    });',
  );
  $export['openlayers_examples_blue_marker'] = $ol_style;

  return $export;
}
