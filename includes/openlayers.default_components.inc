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
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'component_bootstrapjs_popup';
  $ol_component->name = 'Bootstrap JS popup';
  $ol_component->description = 'Bootstrap JS popup component is a component who allows you to display popup when clicking on a feature. It requires the bootstrapjs module to work.';
  $ol_component->class = 'openlayers__component__bootstrapjs_popup';
  $ol_component->options = array();
  $export['component_bootstrapjs_popup'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'component_bootstrapjs_alert';
  $ol_component->name = 'Bootstrap JS alert';
  $ol_component->description = 'Display an alert on the top of the map.';
  $ol_component->class = 'openlayers__component__bootstrapjs_alert';
  $ol_component->options = array(
    'message' => '<strong>Success !</strong>The map has been loaded.',
  );
  $export['component_bootstrapjs_alert'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = TRUE; /* Edit this to true to make a default component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'map_edit_form_values';
  $ol_component->name = 'Map edit form values';
  $ol_component->description = 'Provides values for the center, rotation and zoom in the map edit form.';
  $ol_component->class = 'openlayers__component__setvalues';
  $ol_component->options = array(
    'latitude' => 'edit-options-view-center-lat',
    'longitude' => 'edit-options-view-center-lon',
    'rotation' => 'edit-options-view-rotation',
    'zoom' => 'edit-options-view-zoom',
  );
  $export['map_edit_form_values'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = TRUE; /* Edit this to true to make a default component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'map_edit_form_setcenter';
  $ol_component->name = 'Map center on mouse click';
  $ol_component->description = 'Upon clicking, center the map at the mouse position.';
  $ol_component->class = 'openlayers__component__js';
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
