<div class="sponsors-wrapper">
  <div class="container">
    <div class="row sponsors-row">
      <div class="col-xs-12">
        <?php foreach ($level_4_sponsors as $sponsors_row) { ?>
          <div class="row sponsors-row">
            <?php foreach ($sponsors_row as $sponsor) { ?>
              <div class="col-sm-6">
                <?php print render($sponsor['logo']); ?>
                <?php print render($sponsor['title']); ?>
              </div>
            <?php }; ?>
          </div>
        <?php }; ?>
      </div>
    </div>
  </div>
</div>

<div class="sponsors-wrapper">
  <div class="container">
    <div class="row sponsors-row">
      <div class="col-xs-12">
        <?php foreach ($level_3_sponsors as $sponsors_row) { ?>
          <div class="row sponsors-row">
            <?php foreach ($sponsors_row as $sponsor) { ?>
              <div class="col-sm-4">
                <?php print render($sponsor['logo']); ?>
                <?php print render($sponsor['title']); ?>
              </div>
            <?php }; ?>
          </div>
        <?php }; ?>
      </div>
    </div>
  </div>
</div>

<div class="sponsors-wrapper">
  <div class="container">
    <div class="row sponsors-row">
      <div class="col-xs-12">
        <?php foreach ($level_2_sponsors as $sponsors_row) { ?>
          <div class="row sponsors-row">
            <?php foreach ($sponsors_row as $sponsor) { ?>
              <div class="col-sm-4">
                <?php print render($sponsor['logo']); ?>
                <?php print render($sponsor['title']); ?>
              </div>
            <?php }; ?>
          </div>
        <?php }; ?>
      </div>
    </div>
  </div>
</div>

<div class="sponsors-wrapper">
  <div class="container">
    <div class="row sponsors-row">
      <div class="col-xs-12">
        <?php foreach ($level_1_sponsors as $sponsors_row) { ?>
          <div class="row sponsors-row">
            <?php foreach ($sponsors_row as $sponsor) { ?>
              <div class="col-sm-4">
                <?php print render($sponsor['logo']); ?>
                <?php print render($sponsor['title']); ?>
              </div>
            <?php }; ?>
          </div>
        <?php }; ?>
      </div>
    </div>
  </div>
</div>

