<?php
/**
 * A page that displays listings of all products
 */
?>

<?php foreach ($breweries as $breweries_row) { ?>
  <div class="row">
    <?php foreach ($breweries_row as $brewery) { ?>
      <div class="col-sm-4">
        <?php print render($brewery['title']); ?>
      </div>
    <?php }; ?>
  </div>
<?php }; ?>

