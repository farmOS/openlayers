<?php
/**
 * @file
 * Provide default components.
 */

/**
 * Implements hook_default_components().
 */
function openlayers_default_components() {
  $export = array();

  $ol_component = new stdClass();
  $ol_component->disabled = TRUE; /* Edit this to true to make a default component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'map_edit_form_values';
  $ol_component->name = 'Map edit form values';
  $ol_component->description = 'Provides values for the center, rotation and zoom in the map edit form.';
  $ol_component->class = '\\Drupal\\openlayers\\Component\\setvalues';
  $ol_component->options = array(
    'latitude' => 'edit-options-view-center-lat',
    'longitude' => 'edit-options-view-center-lon',
    'rotation' => 'edit-options-view-rotation',
    'zoom' => 'edit-options-view-zoom',
  );
  $export['map_edit_form_values'] = $ol_component;

  // @todo: Transform this into a real component, without inlinejs.
  $ol_component = new stdClass();
  $ol_component->disabled = TRUE; /* Edit this to true to make a default component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'map_edit_form_setcenter';
  $ol_component->name = 'Map center on mouse click';
  $ol_component->description = 'Upon clicking, center the map at the mouse position.';
  $ol_component->class = '\\Drupal\\openlayers\\Component\\inlineJS';
  $ol_component->options = array(
    'javascript' => 'data.map.on(\'click\', function(evt){
  var coordinate = evt.coordinate;
  var pan = ol.animation.pan({
    duration: 2000,
    source: (data.map.getView().getCenter())
  });
  data.map.beforeRender(pan);
  data.map.getView().setCenter(coordinate);
});',
  );
  $export['map_edit_form_setcenter'] = $ol_component;

  return $export;
}
