<div class="row">
  <div class="col-sm-12">
    <table class="table table-responsive table-striped">
      <thead>
        <tr>
          <th>Name</th>
          <th>Phone</th>
          <th>Accepted?</th>
          <th>Shift</th>
          <th>Job</th>
        </tr>
      </thead>
      <tbody>
        <?php foreach ($volunteers as $volunteer) { ?>
          <tr>
            <td><?php print render($volunteer['name']); ?> (<?php print render($volunteer['email']); ?>)</td>
            <td><?php print render($volunteer['phone']); ?></td>
            <td>Yes</td>
            <td>Early</td>
            <td>Something something</td>
          </tr>
        <?php }; ?>
      </tbody>
    </table>
  </div>
</div>
