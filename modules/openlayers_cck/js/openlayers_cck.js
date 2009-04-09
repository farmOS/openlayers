// $Id$

/**
 * @notes
 *
 *
 */

/**
 * When document is ready for JS
 * 
 * Add the themed map container (HTML) to the document. 
 * Also set-up the click functionality for the Show/Hide WKT Fields
 */
jQuery(document).ready(function() {
  // Go through CCK Fields and diplay map
  var fieldContainer = '';
  for (var map in Drupal.settings.openlayers_cck.maps) {
    fieldContainer = Drupal.settings.openlayers_cck.maps[map].field_container;
    // Add Themed Map container
    $('#' + fieldContainer).before(Drupal.settings.openlayers_cck.maps[map].field_map_themed);
    $('#' + fieldContainer).hide();
    
    // Define click actions for WKT Switcher
    $('#' + map + '-wkt-switcher').click(function() {
      var mapid = $(this).attr('rel');
      var fieldContainer = Drupal.settings.openlayers_cck.maps[mapid].field_container;
      $('#' + fieldContainer).toggle();
      return false;
    });
  }
});

/**
 * OpenLayers CCK Feature Added Handler
 * 
 * This function is triggered when a feature is added by the user
 */
function openlayersCCKFeatureAdded(event) {
	//Get the feature we have just added out of the event object
  var feature = event.feature;
  
  // Make some variables
  var featureCount = feature.layer.features.length;
  var featureNew = featureCount - 1;
  var mapid = feature.layer.map.mapid;
  
  // Get field names
  var fieldName;
  for (var map in Drupal.settings.openlayers_cck.maps) {
    if (map == mapid) {
      fieldName = Drupal.settings.openlayers_cck.maps[map].field_name_js;
    }
  }
  
  // This is the id of the textfield we will be assigning this feature to.
  var wktFieldNewID = 'edit-' + fieldName + '-' + featureNew + '-wkt';
  // This is the "Add another item" button
  var wktFieldAddID = 'edit-' + fieldName + '-' + fieldName + '-add-more';
  
  // Clone the geometry so we may safetly work on it without hurting the feature
  var geometry = feature.geometry.clone();
    
  // Assign field to feature
  feature.drupalField = wktFieldNewID;
  // geometry.transform(map_proj, maps[field_name]['dbproj']);
  var wkt = geometry.toString();
  $('#' + wktFieldNewID).val(wkt);
    
  // Add another field ..
  // @@BUG:  When triggering this function it is reloading all of Drupal.settings.openlayers.  On the reload for some reason it is only reloading our current CCK-field, not all CCK-fields, and so is causing the error: Drupal.settings.openlayers.maps[parsedRel.mapid] is undefined
  $('#' + wktFieldAddID).trigger('mousedown');
}

/**
 * Get Values From CCK and populate the map with shapes
 */
function openlayersCCKPopulateMap(mapid){  
  var featuresToAdd = [];
  var wktFormat = new OpenLayers.Format.WKT();
  var fieldContainer = Drupal.settings.openlayers_cck.maps[mapid].field_container;
  
  // Cycle through the fieldContainer item and read WKT from all the textareas
  $('#' + fieldContainer + ' textarea').each(function(){
    if ($(this).val() != ''){
    	//read the wkt values into an OpenLayers geometry object
      var newFeature = wktFormat.read($(this).val());
      if (typeof(newFeature) == "undefined"){
        alert(Drupal.t('WKT is not valid'));
      }
      else{
      	// @@TODO: project the geometry if our map has a different geospatial projection as our CCK geo data.
        // newFeature.geometry.transform(maps[field_name]['dbproj'], map_proj);
        
        // Link the feature to the field.
        newFeature.drupalField = $(this).attr('id');
        // Queue the feature for addition to the layer.
        featuresToAdd.push(newFeature);
      }
    }
  });
  
  // Add features to vector
  if (featuresToAdd.length != 0){
    Drupal.openlayers.activeObjects[mapid].layers['default_vector'].addFeatures(featuresToAdd);
  }
}


/**
 * When the layer is done loading, load in the values from the CCK text fields if it is the correct layer.
 */
function openlayersCCKLoadValues(event){
  if (event.layer.drupalId == "default_vector"){
    openlayersCCKPopulateMap(event.layer.map.mapid);
  }
}


/**
 * When the any feature on the layer is modified, fill in the WKT values into the text fields
 */
function openlayersCCKFeatureModified(event){
  
  // @@TODO: If modified, update CCK fields
  
  // @@TODO: If deleted, remove value form field
  
}