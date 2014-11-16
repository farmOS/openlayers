<?php
/**
 * @file
 * Class openlayers_interaction.
 */

namespace Drupal\openlayers;

/**
 * Class openlayers_interaction.
 */
abstract class Interaction extends Object implements InteractionInterface {
  public function getType() {
    return 'Interaction';
  }
}
