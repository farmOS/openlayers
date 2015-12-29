<?php
/**
 * @file
 * Default theme implementation to display an Openlayers map.
 *
 * Debug the result of the function get_defined_vars() to have an overview
 * of all the variables you have access to.
 */
?>

<?php if ($openlayers['openlayers']): ?>
  <?php print render($openlayers['openlayers']); ?>
<?php endif; ?>

<?php if ($openlayers['description']): ?>
  <?php print render($openlayers['description']); ?>
<?php endif; ?>

<?php if ($openlayers['capabilities']): ?>
  <?php print render($openlayers['capabilities']); ?>
<?php endif; ?>
