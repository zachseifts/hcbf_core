<?php foreach ($bands as $band) { ?>
<div class="wrapper">
  <div class="container">
    <div class="row">
      <div class="col-xs-12">
        <?php print render($band['title']); ?>
      </div>
    </div>
    <div class="row">
      <div class="col-xs-12 col-sm-3">
        <img src="http://placehold.it/250x250" />
      </div>
      <div class="col-xs-12 col-sm-9">
        <?php print render($band['description']); ?>
        <?php print render($band['website']); ?>
      </div>
    </div>
  </div>
</div>
<?php }; ?>
