<div id="getting-there-wrapper" class="wrapper">
  <div class="container">

    <div class="row">
      <div class="col-xs-12 col-sm-8">
        <div class="container-fluid">
          <div class="row">

            <div class="col-xs-12 col-sm-4">

              <div class="text-center">
                <i class="icon fa fa-ticket fa-4x"></i>
              </div>
              <div class="page-header">
                <h3 class="text-center">VIP Tickets</h3>
              </div>

              <ul>
                <li>Priority entry to the event</li>
                <li>An extra hour of tasting</li>
                <li>1 Free T-shirt</li>
                <li>Free food voucher to one our food vendors</li>
              </ul>

              <div class="text-center">
                <a href="<?php print variable_get('hcbf_core_vip_ticket_link', '#'); ?>" class="btn btn-success btn-lg">
                  $<?php print variable_get('hcbf_core_vip_ticket_price', '80.00'); ?>
                </a>
              </div>

            </div>

            <div class="col-xs-12 col-sm-4">
              <div class="text-center">
                <i class="icon fa fa-ticket fa-4x"></i>
              </div>
              <div class="page-header">
                <h3 class="text-center">General Admission</h3>
              </div>

              <ul>
                <li>Access to 50 craft breweries</li>
                <li>9 local food vendors</li>
                <li>4 hours of live music</li>
                <li>Access to seminars</li>
              </ul>

              <div class="text-center">
                <a href="<?php print variable_get('hcbf_core_regular_ticket_link', '#'); ?>" class="btn btn-success btn-lg">
                  $<?php print variable_get('hcbf_core_regular_ticket_price', '40.00'); ?>
                </a>
              </div>
            </div>

            <div class="col-xs-12 col-sm-4">
              <div class="text-center">
                <i class="icon fa fa-ticket fa-4x"></i>
              </div>
              <div class="page-header">
                <h3 class="text-center">Designated Driver</h3>
              </div>

              <ul>
                <li>9 local food vendors</li>
                <li>4 hours of live music</li>
                <li>Ability to enjoy the beautiful mountain setting</li>
                <li>Privilege to get your friends home safe</li>
              </ul>

              <div class="text-center">
                <a href="<?php print variable_get('hcbf_core_dd_ticket_link', '#'); ?>" class="btn btn-success btn-lg">
                  $<?php print variable_get('hcbf_core_dd_ticket_price', '10.00'); ?>
                </a>
              </div>
            </div>

          </div>
        </div>
      </div>

      <div class="col-xs-12 col-sm-4">
        <div class="text-center">
          <i class="icon fa fa-beer fa-5x"></i>
        </div>
        <div class="page-header">
          <h1 class="text-center">The Festivities</h1>
        </div>
        <p class="text-center">Join us at the High Country Fairgrounds in Boone, North Carolina on Saturday, August 29, 2015 from 3:00 pm to 8:00 pm to sample a variety of craft beer, craft food, educational seminars, and live music.</p>
      </div>

    </div>
  </div>
</div>
    
<div id="video-wrapper" class="wrapper inverse-wrapper">
  <div class="container">
    <div class="row">
      <div class="col-xs-12 col-sm-8">
        <div class="video-wrapper">
          <iframe src="//player.vimeo.com/video/95663874" width="100%" height="420" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe>
        </div>
      </div>
      <div class="col-xs-12 col-sm-4">
        <h1 class="heading">The High Country Beer Fest is a celebration of craft beer from around the region and the world.</h1>
        <p>Come sample outstanding beers and delicious food in the beautiful high country of North Carolina. Educational seminars will cover aspects of beer tasting, brewing, and food pairing.</p>
      </div>
    </div>
  </div>
</div>

<div id="about-wrapper" class="wrapper">
  <div class="container">
    <div class="row">
      <div class="col-xs-12 col-md-6">
        <?php print theme('hcbf_breweries_registration'); ?>
      </div>
      <div class="col-xs-12 col-md-6">
        <?php print theme('hcbf_sponsor_registration'); ?>
      </div>
    </div>
  </div>
</div>

