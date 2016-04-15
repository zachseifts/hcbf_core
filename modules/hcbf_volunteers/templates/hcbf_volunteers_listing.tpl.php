<?php
/**
 * Template for the volunteer admin page.
 */
?>

<div class="volunteers">
<?php if ($volunteers): ?>
  <table>
    <thead>
      <tr>
        <th>Name</th>
        <th>Phone number</th>
        <th>Date of birth</th>
        <th>Previous volunteer?</th>
        <th>Accepted</th>
      </tr>
    </thead>
    <tbody>
      <?php foreach($volunteers as $volunteer): ?>
        <tr>
          <td>
            <?php print $volunteer->field_hcbf_account_name->value(); ?>
            (<?php print l($volunteer->mail->value(), 'maito:' . $volunteer->mail->value(), array('external' => TRUE)); ?>)
          </td>
          <td><?php print l($volunteer->field_hcbf_account_phone->value(), 'tel:' . $volunteer->field_hcbf_account_phone->value(), array('external' => TRUE)); ?></td>
          <td><?php print $volunteer->field_hcbf_account_dob->value(); ?></td>
          <td><?php print $volunteer->field_hcbf_account_previous->value(); ?></td>
          <td><?php print ($volunteer->field_hcbf_account_accepted->value() ? t('Yes') : l('Accept volunteer', '#')); ?></td>
        </tr>
      <?php endforeach; ?>
    </tbody>
  </table>
<?php else: ?>
  <h2>There are no volunteers yet.</h2>
<?php endif; ?>
</div>

