<?php
/**
 * Template for the volunteer admin page.
 */
?>

<div class="volunteers">
<?php if ($volunteers): ?>
  <h2>There are volunteers.</h2>
  <table>
    <thead>
      <tr>
        <th>Name</th>
        <th>Phone number</th>
        <th>Approved</th>
      </tr>
    </thead>
    <tbody>
      <?php foreach($volunteers as $volunteer): ?>
        <tr>
          <td><?php print $volunteer->name->value(); ?></td>
          <td><?php print $volunteer->field_hcbf_account_phone->value(); ?></td>
          <td><?php print $volunteer->name->value(); ?></td>
        </tr>
      <?php endforeach; ?>
    </tbody>
  </table>
<?php else: ?>
  <h2>There are no volunteers yet.</h2>
<?php endif; ?>
</div>

