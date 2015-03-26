<div class="breweries">
  <h2>Current breweries</h2>
  <table>
    <thead>
      <tr>
        <th>Name</th>
        <th>Location</th>
        <th>Accepted</th>
        <th colspan="3">&nbsp;</th>
      </tr>
    </thead>
    <tbody>

      <?php foreach ($breweries as $brewery): ?>
      <tr>
        <tr>
          <td><?php print $brewery['name']; ?></td>
          <td><?php print $brewery['location']; ?></td>
          <td><?php print $brewery['accepted']; ?></td>
          <td><?php print $brewery['view']; ?></td>
          <td><?php print $brewery['edit']; ?></td>
          <td><?php print $brewery['delete']; ?></td>
        </tr>
      </tr>
      <?php endforeach; ?>

  </table>
</div>
