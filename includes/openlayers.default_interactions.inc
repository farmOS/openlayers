<?php
/**
 * @file
 * Provide default interactions.
 */

/**
 * Implements hook_default_interactions().
 */
function openlayers_default_interactions() {
  $export = array();

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'interaction_doubleclickzoom';
  $ol_interaction->name = 'DoubleClickZoom';
  $ol_interaction->description = 'DoubleClickZoom interaction description';
  $ol_interaction->class = 'openlayers__interaction__doubleclickzoom';
  $ol_interaction->options = array();
  $export['interaction_doubleclickzoom'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'interaction_draganddrop';
  $ol_interaction->name = 'DragAndDrop';
  $ol_interaction->description = 'DragAndDrop interaction description';
  $ol_interaction->class = 'openlayers__interaction__draganddrop';
  $ol_interaction->options = array();
  $export['interaction_draganddrop'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'interaction_dragbox';
  $ol_interaction->name = 'DragBox';
  $ol_interaction->description = 'DragBox interaction description';
  $ol_interaction->class = 'openlayers__interaction__dragbox';
  $ol_interaction->options = array();
  $export['interaction_dragbox'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'interaction_dragpan';
  $ol_interaction->name = 'DragPan';
  $ol_interaction->description = 'DragPan interaction description';
  $ol_interaction->class = 'openlayers__interaction__dragpan';
  $ol_interaction->options = array(
    'decay' => -0.005,
    'minVelocity' => 0.05,
    'delay' => 100,
  );
  $export['interaction_dragpan'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'interaction_dragrotate';
  $ol_interaction->name = 'DragRotate';
  $ol_interaction->description = 'DragRotate interaction description';
  $ol_interaction->class = 'openlayers__interaction__dragrotate';
  $ol_interaction->options = array();
  $export['interaction_dragrotate'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'interaction_dragrotateandzoom';
  $ol_interaction->name = 'DragRotateAndZoom';
  $ol_interaction->description = 'DragRotateAndZoom interaction description';
  $ol_interaction->class = 'openlayers__interaction__dragrotateandzoom';
  $ol_interaction->options = array();
  $export['interaction_dragrotateandzoom'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'interaction_dragzoom';
  $ol_interaction->name = 'DragZoom';
  $ol_interaction->description = 'DragZoom interaction description';
  $ol_interaction->class = 'openlayers__interaction__dragzoom';
  $ol_interaction->options = array();
  $export['interaction_dragzoom'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'interaction_draw';
  $ol_interaction->name = 'Draw';
  $ol_interaction->description = 'Draw interaction description';
  $ol_interaction->class = 'openlayers__interaction__draw';
  $ol_interaction->options = array();
  $export['interaction_draw'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'interaction_keyboardpan';
  $ol_interaction->name = 'KeyboardPan';
  $ol_interaction->description = 'KeyboardPan interaction description';
  $ol_interaction->class = 'openlayers__interaction__keyboardpan';
  $ol_interaction->options = array();
  $export['interaction_keyboardpan'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'interaction_keyboardzoom';
  $ol_interaction->name = 'KeyboardZoom';
  $ol_interaction->description = 'KeyboardZoom interaction description';
  $ol_interaction->class = 'openlayers__interaction__keyboardzoom';
  $ol_interaction->options = array();
  $export['interaction_keyboardzoom'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'interaction_modify';
  $ol_interaction->name = 'Modify';
  $ol_interaction->description = 'Modify interaction description';
  $ol_interaction->class = 'openlayers__interaction__modify';
  $ol_interaction->options = array();
  $export['interaction_modify'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'interaction_mousewheelzoom';
  $ol_interaction->name = 'MouseWheelZoom';
  $ol_interaction->description = 'MouseWheelZoom interaction description';
  $ol_interaction->class = 'openlayers__interaction__mousewheelzoom';
  $ol_interaction->options = array();
  $export['interaction_mousewheelzoom'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'interaction_pinchrotate';
  $ol_interaction->name = 'PinchRotate';
  $ol_interaction->description = 'PinchRotate interaction description';
  $ol_interaction->class = 'openlayers__interaction__pinchrotate';
  $ol_interaction->options = array();
  $export['interaction_pinchrotate'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'interaction_pinchzoom';
  $ol_interaction->name = 'PinchZoom';
  $ol_interaction->description = 'PinchZoom interaction description';
  $ol_interaction->class = 'openlayers__interaction__pinchzoom';
  $ol_interaction->options = array();
  $export['interaction_pinchzoom'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'interaction_pointer';
  $ol_interaction->name = 'Pointer';
  $ol_interaction->description = 'Pointer interaction description';
  $ol_interaction->class = 'openlayers__interaction__pointer';
  $ol_interaction->options = array();
  $export['interaction_pointer'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'interaction_select';
  $ol_interaction->name = 'Select';
  $ol_interaction->description = 'Select interaction description';
  $ol_interaction->class = 'openlayers__interaction__select';
  $ol_interaction->options = array();
  $export['interaction_select'] = $ol_interaction;

  return $export;
}
