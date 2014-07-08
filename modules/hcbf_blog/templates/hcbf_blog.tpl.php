<div class="wrapper wrapper-blog">
  <div class="container">
    <div class="row">
      <div class="col-xs-12 col-md-9">
        <?php if (!empty($posts)): ?>
          <?php foreach ($posts as $post) { ?>
            <?php print render($post['title']); ?>
            <?php print render($post['body']); ?>
          <?php }; ?>
          <?php print theme('pager'); ?>
        <?php else: ?>
          <h1>There are no blog posts.</h1>
        <?php endif; ?>
      </div>
      <div class="col-xs-12 col-md-3">

        <div class="well">
          <div class="text-center">
            <i class="icon fa fa-ticket fa-5x"></i>
          </div>
          <div class="page-header">
            <h2 class="text-center">Buy Tickets</h2>
          </div>
          <p>Tickets are on sale now!</p>
          <div class="table-responsive">
            <table class="table ticket-table">
              <tbody>
                <tr>
                  <td>General Admission</td>
                  <td><a class="btn btn-success btn-sm" href="http://www.etix.com/ticket/online/performanceSearch.jsp?performance_id=1820947">$40.00</a></td>
                </tr>
                <tr>
                  <td>Designated Driver</td>
                  <td><a class="btn btn-success btn-sm" href="http://www.etix.com/ticket/online/performanceSearch.jsp?performance_id=1821065">$10.00</a></td>
                </tr>
              </tbody>
            </table>
          </div>
        </div>

        <div class="well">
          <div class="page-header">
            <h2 class="text-center">Recent posts</h2>
          </div>

          <ul class="nav nav-pills nav-stacked">
            <?php if (!empty($recent_posts)): ?>
              <?php foreach ($recent_posts as $post) { ?>
                <?php print render($post['link']); ?>
              <? }; ?>
            <?php else: ?>
              <li><a href="#">No recent posts</a></li>
            <?php endif; ?>
          </ul>
        </div>

      </div>
    </div>
  </div>
</div>
