<?php
/**
 * A page that displays listings of all products
 */
?>

<div class="breweries-wrapper">
  <div class="container">
    <div class="col-xs-12">
      <?php foreach ($breweries as $breweries_row) { ?>
        <div class="row brewery-row">
          <?php foreach ($breweries_row as $brewery) { ?>
            <div class="col-sm-4">
              <?php print render($brewery['logo']); ?>
              <?php print render($brewery['title']); ?>
              <?php print render($brewery['location']); ?>
            </div>
          <?php }; ?>
        </div>
      <?php }; ?>
    </div>
  </div>
</div>

