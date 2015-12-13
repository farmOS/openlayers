<?php
/**
 * @file
 * Source: Views.
 */

namespace Drupal\openlayers_views\Plugin\Source\Views;
use Drupal\openlayers\Types\Source;

/**
 * Class Views.
 *
 * @OpenlayersPlugin(
 *  id = "Views"
 * )
 */
class Views extends Source {

  /**
   * @inheritDoc
   */
  public function optionsForm(&$form, &$form_state) {
    $options = array();
    foreach (views_get_all_views() as $view) {
      foreach ($view->display as $display => $data) {
        if ($display != 'default') {
          $view->set_display($display);
          $viewname = sprintf('%s (%s)', $view->human_name, $view->name);
          if ($view->display_handler->get_option('style_plugin') == 'openlayers_source_vector') {
            $options[$viewname][$view->name.':'.$display] = sprintf('%s:%s', $view->human_name,$display);
          }
          if ($view->display_handler->get_option('style_plugin') == 'openlayers_map_views') {
            $options[$viewname][$view->name.':'.$display] = sprintf('%s:%s', $view->human_name,$display);
          }
        }
      }
    }

    $form['view'] = array(
      '#type' => 'select',
      '#title' => 'View and display',
      '#options' => $options,
      '#default_value' => $this->getOption('view'),
      '#required' => TRUE
    );

    return parent::optionsForm($form, $form_state);
  }

  /**
   * @inheritDoc
   */
  public function init() {
    parent::init();
    $this->features = array();

    list($views_id, $display_id) = explode(':', $this->options['view'], 2);
    $view = views_get_view($views_id);
    if ($view && $view->access($display_id)) {
      $view->set_display($display_id);
      if (empty($view->current_display) || ((!empty($display_id)) && $view->current_display != $display_id)) {
        if (!$view->set_display($display_id)) {
          return FALSE;
        }
      }

      $view->pre_execute();
      $view->init_style();
      $view->execute();
      // do not render the map, just return the features.
      $view->style_plugin->options['skipMapRender'] = TRUE;
      $this->features += $view->style_plugin->render();
      $view->post_execute();
    }

    $this->options['features'] = $this->features;
  }

}
