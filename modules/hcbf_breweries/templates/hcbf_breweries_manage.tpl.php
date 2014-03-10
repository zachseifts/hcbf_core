<div class="row">
  <div class="col-sm-12">
    <div class="table-responsive">
      <table class="table">
        <thead>
          <tr>
            <th>Name of brewery</th>
          </tr>
        </thead>
        <tbody>
          <?php foreach ($volunteers as $volunteer) { ?>
            <tr class="<?php print $volunteer['row_class']; ?>">
            </tr>
          <?php }; ?>
        </tbody>
      </table>
    </div>
  </div>
</div>
