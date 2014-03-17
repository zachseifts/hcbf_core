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
          <?php foreach ($breweries as $brewery) { ?>
            <tr>
              <td>
                <?php print render($brewery['name']); ?>
              </td>
            </tr>
          <?php }; ?>
        </tbody>
      </table>
    </div>
  </div>
</div>
