<?php
/**
 * @file
 * Component: Bootstap JS Popup.
 */

/**
 * Plugin definition.
 */
function openlayers_openlayers__component__bootstrapjs_popup_openlayers_component() {
  return array(
    'handler' => array(
      'class' => 'openlayers__component__bootstrapjs_popup',
      'file' => 'openlayers__component__bootstrapjs_popup.inc',
    ),
  );
}

/**
 * Class openlayers__component__bootstrapjs_popup.
 */
class openlayers__component__bootstrapjs_popup extends openlayers_component {

  /**
   * {@inheritdoc}
   */
  public function attached() {
    $attached = parent::attached();
    $attached['libraries_load'][] = array('bootstrapjs');
    return $attached;
  }

  /**
   * {@inheritdoc}
   */
  public function dependencies() {
    return array(
      'bootstrapjs',
    );
  }

}
