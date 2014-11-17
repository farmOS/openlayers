<?php
/**
 * @file
 * Interface openlayers_object_interface.
 */

namespace Drupal\openlayers;

/**
 * Interface openlayers_object_interface.
 */
interface ObjectInterface {
  /**
   * Return a list of default properties.
   *
   * @return array
   *   The default properties for this class.
   */
  public function default_properties();

  /**
   * Initializes the object.
   *
   * @param array $data
   *   The configuration data.
   */
  public function init(array $data);

  /**
   * The type of this object.
   *
   * @see openlayers_object_types()
   *
   * @return string|FALSE
   *   The object type or FALSE on failure.
   */
  // @todo: Shouldn't we automatically compute this based on the fully qualified class name ?
  // ex: \Drupal\openlayers\Control\MousePosition => Control
  public function getType();

  /**
   * Returns the plugin definition.
   *
   * @return array
   *   The plugin definition.
   */
  public function getPlugin();

  /**
   * @TODO was does this do?
   */
  public function develop();

  /**
   * @TODO was does this?
   *
   * @param string|array $parents
   */
  public function clearOption($parents);

  /**
   * Returns an option.
   *
   * @param string|array $parents
   *   @TODO Define how this has to look like if it is an array.
   * @param mixed $default_value
   *   The default value to return if the option isn't set. Set to NULL if not
   *   defined.
   *
   * @return mixed
   *   The value of the option or the defined default value.
   */
  public function getOption($parents, $default_value = NULL);

  /**
   * Set an option.
   *
   * @param string|array $parents
   *   @TODO Define how this has to look like if it is an array.
   *
   * @param mixed $value
   *   The value to set.
   */
  public function setOption($parents, $value);

  /**
   * Provides the options form to configure this object.
   *
   * @param array $form
   *   The form array by reference.
   * @param array $form_state
   *   The form_state array by reference.
   */
  public function options_form(&$form, &$form_state);

  /**
   * Validation callback for the options form.
   *
   * @param array $form
   *   The form array.
   * @param array $form_state
   *   The form_state array by reference.
   */
  public function options_form_validate($form, &$form_state);

  /**
   * Submit callback for the options form.
   *
   * @param array $form
   *   The form array.
   * @param array $form_state
   *   The form_state array by reference.
   */
  public function options_form_submit($form, &$form_state);

  /**
   * Returns a list of attachments for building the render array.
   *
   * @param \Drupal\openlayers\ObjectInterface $context
   *   The object the attachments are attached to.
   *
   * @return array
   *   The attachments to add.
   */
  public function attached(\Drupal\openlayers\ObjectInterface $context);

  /**
   * Defines dependencies.
   *
   * @TODO Define how this has to look like.
   *
   * @return array
   *   The dependencies.
   */
  public function dependencies();

  /**
   * Returns the object as JS compatible array.
   *
   * @return array
   *   The array representation of this object.
   */
  public function toJSArray();

  /**
   * Whether or not this object has to be processed asynchronously.
   *
   * If true the map this object relates to won't be processes right away by
   * Drupals behaviour attach.
   *
   * @return bool
   *   Whether or not this object has to be processed asynchronously.
   */
  public function isAsynchronous();
}
