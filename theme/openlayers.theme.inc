<?php

/**
 * @file
 * This file holds all the theme related functions.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function template_preprocess_openlayers(&$variables) {
  $variables['theme_hook_suggestions'][] = 'openlayers__' . str_replace('-', '_', $variables['openlayers']['#map']->getMachineName());
}
