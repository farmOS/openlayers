<?php
/**
 * @file
 * Component: OL3Cesium.
 */

namespace Drupal\openlayers_cesium\Plugin\Component\OL3Cesium;

use Drupal\openlayers\Config;
use Drupal\openlayers\Types\Component;
use Drupal\openlayers\Types\ObjectInterface;

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

    if (Config::get('openlayers.debug', FALSE)) {
      $attached['libraries_load']['openlayers3_integration'] = array('openlayers3_integration', 'debug');
    };

    $library = libraries_detect('cesium');
    if ($library['installed'] == TRUE) {
      $data = "var CESIUM_BASE_URL = '" . url($library['library path'] . '/Build/Cesium/') . "';";
      $attached['js'][] = drupal_realpath(file_unmanaged_save_data($data, 'public://openlayers_cesium_base_url.js', FILE_EXISTS_REPLACE));
    }

    return $attached;
  }

}
