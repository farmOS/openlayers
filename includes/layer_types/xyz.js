// $Id$

/**
 * @file
 * Layer handler for XYZ layers
 */

/**
 * Openlayer layer handler for XYZ layer
 */
Drupal.openlayers.layer.xyz = function (name, map, options) {
  var styleMap = Drupal.openlayers.getStyleMap(map, name);
  if (options.maxExtent !== undefined) {
    options.maxExtent = new OpenLayers.Bounds.fromArray(options.maxExtent) || new OpenLayers.Bounds(-20037508.34, -20037508.34, 20037508.34, 20037508.34);
  }
  if (options.type === undefined){
    options.type = "png";
  }
  options.projection = new OpenLayers.Projection('EPSG:'+options.projection);
  options.sphericalMercator = true;
  
  var layer = new OpenLayers.Layer.XYZ(name, options.base_url, options);
  layer.styleMap = styleMap;
  return layer;
};
