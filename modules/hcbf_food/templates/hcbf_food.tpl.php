<?php foreach ($foods as $food) { ?>
<div class="wrapper">
  <div class="container">
    <div class="row">
      <div class="col-xs-12">
        <?php print render($food['title']); ?>
      </div>
    </div>
    <div class="row">
      <div class="col-xs-12 col-sm-3">
        <?php print render($food['image']); ?>
      </div>
      <div class="col-xs-12 col-sm-9">
        <?php print render($food['description']); ?>
        <?php print render($food['website']); ?>
      </div>
    </div>
  </div>
</div>
<?php }; ?>


