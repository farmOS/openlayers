<?php
/**
 * @file
 * Component: OL3Cesium.
 */

namespace Drupal\openlayers_cesium\Plugin\Component\OL3Cesium;

use Drupal\openlayers\Config;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Component;

/**
 * Class OL3Cesium.
 *
 * @OpenlayersPlugin(
 *   id = "OL3Cesium",
 *   description = "Provides a Openlayers Cesium component."
 * )
 */
class OL3Cesium extends Component {
  /**
   * @inheritDoc
   */
  public function attached() {
    $attached = parent::attached();
    $attached['libraries_load'][] = array(
      'ol3-cesium',
    );

    $library = libraries_detect('cesium');
    if ($library['installed'] == TRUE) {
      $data = "var CESIUM_BASE_URL = '" . url($library['library path'] . '/Build/Cesium/') . "';";
      $attached['js'][] = file_create_url(file_unmanaged_save_data($data, 'public://openlayers_cesium_base_url.js', FILE_EXISTS_REPLACE), array('absolute' => TRUE));
    }

    return $attached;
  }

}
