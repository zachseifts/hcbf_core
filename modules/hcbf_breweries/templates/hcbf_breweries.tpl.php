<?php
/**
 * A page that displays listings of all products
 */
?>

<?php foreach ($breweries as $breweries_row) { ?>
  <div class="row">
    <?php foreach ($breweries_row as $brewery) { ?>
      <div class="col-sm-4">
        <img src="http://placehold.it/220x220" />
        <?php print render($brewery['title']); ?>
        <?php print render($brewery['location']); ?>
        <?php print render($brewery['website']); ?>
      </div>
    <?php }; ?>
  </div>
<?php }; ?>

