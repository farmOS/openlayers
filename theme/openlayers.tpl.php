<?php
/**
 * @file
 * Default theme implementation to display an Openlayers map.
 *
 * Debug the result of the function get_defined_vars() to have an overview
 * of all the variables you have access to.
 */
?>

<?php if (isset($openlayers['map'])): ?>
  <?php print render($openlayers['map']); ?>
<?php endif; ?>

<?php if (isset($openlayers['description'])): ?>
  <?php print render($openlayers['description']); ?>
<?php endif; ?>

<?php if (isset($openlayers['parameters'])): ?>
  <?php print render($openlayers['parameters']); ?>
<?php endif; ?>

<?php if (isset($openlayers['capabilities'])): ?>
  <?php print render($openlayers['capabilities']); ?>
<?php endif; ?>
