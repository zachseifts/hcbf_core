<div class="heading">
  <h1><?php print $festival['date']; ?></h1>
<div>

<div class="sponsors">
  <h2>Current sponsors</h2>
  <ul>
    <?php foreach ($festival['sponsors'] as $sponsor): ?>
    <li><?php print $sponsor['name']; ?></li>
    <?php endforeach; ?>
  </ul>
</div>
