<?php if (variable_get('hcbf_breweries_week_of_message', 0) == 1): ?>
<div id="week-of-wrapper" class="wrapper">
  <div class="container">
    <div class="row">
      <div class="col-xs-12">
        <div class="page-header">
          <h1>The festival is this Saturday! What should I bring?</h1>
        </div>
      </div>
    </div>

    <div class="row">
      <div class="col-xs-12 col-sm-4">
        <div class="text-center">
          <i class="icon fa fa-check-square fa-5x"></i>
        </div>
        <div class="text-center">
          <h2>Your ID</h2>
        </div>
        <p class="lead">Remember to bring your ID, we check everyone's at the gate. We won't let you in if you don't have it or if you're under 21.</p>
      </div>

      <div class="col-xs-12 col-sm-4">
        <div class="text-center">
          <i class="icon fa fa-check-square fa-5x"></i>
        </div>
        <div class="text-center">
          <h2>Cash</h2>
        </div>
        <p class="lead">Most of our vendors won't have access to the internet during the festival, so cash is the way to go. It makes it easier for everyone.</p>
      </div>

      <div class="col-xs-12 col-sm-4">
        <div class="text-center">
          <i class="icon fa fa-check-square fa-5x"></i>
        </div>
        <div class="text-center">
          <h2>A good attitude</h2>
        </div>
        <p class="lead">We're all here to have fun and enjoy ourselves, the music, the food and the beer.</p>
        <p class="lead">So be cool.</p>
      </div>
    </div>
  </div>
</div>

<hr />
<?php endif; ?>

<div id="getting-there-wrapper" class="wrapper">
  <div class="container">
    <div class="row">
      <div class="col-xs-12 col-sm-4">
        <a href="http://www.center45.com/">
          <img src="/sites/all/modules/custom/hcbf_core/modules/hcbf_home/images/center45.png" class="img-responsive" />
        </a>
      </div>
      <div class="col-xs-12 col-sm-8">
        <h1>Join us on April 30th at <a href="http://www.center45.com/">Center 45</a> for our ticket release party!</h1>
      </div>
    </div>
  </div>
  <?php
/**
* <div class="container">

*   <div class="row">
*     <div class="col-xs-12 col-sm-8">
*       <div class="container-fluid tickets-block">
*         <div class="row">
*
*           <div class="col-xs-12 col-sm-4">
*
*             <div class="text-center">
*               <i class="icon fa fa-ticket fa-5x"></i>
*             </div>
*             <h2 class="text-center">VIP Tickets</h2>
*
*             <p class="lead">VIP Ticket holders get 2:00pm entry to the festival, a special High Country Beer Fest t-shirt and a free food voucher.</p>
*
*             <div class="text-center">
*               <a href="#" 
*                  class="btn btn-danger btn-lg"
*                  disabled="disabled"
*                  data-ga-event
*                  data-ga-category="ticket_link_click"
*                  data-ga-label="homepage"
*                  data-ga-action="vip">
*                 SOLD OUT
*               </a>
*             </div>
*
*           </div>
*
*           <div class="col-xs-12 col-sm-4">
*             <div class="text-center">
*               <i class="icon fa fa-ticket fa-5x"></i>
*             </div>
*             <h2 class="text-center">General Admission</h2>
*
*             <p class="lead">Enjoy access to over 50 craft breweries, local food vendors, seminars and live music.</p>
*
*             <div class="text-center">
*               <?php if (variable_get('hcbf_core_regular_ticket_sold_out', 0) == 0): ?>
*               <a href="<?php print variable_get('hcbf_core_regular_ticket_link', '#'); ?>"
*                  class="btn btn-success btn-lg"
*               <?php else: ?>
*               <a href="#"
*                  class="btn btn-danger btn-lg"
*                  disabled="disabled"
*               <?php endif; ?>
*                  data-ga-event
*                  data-ga-category="ticket_link_click"
*                  data-ga-label="homepage"
*                  data-ga-action="general_admission">
*                <?php if (variable_get('hcbf_core_regular_ticket_sold_out', 0) == 0): ?>
*                 $<?php print variable_get('hcbf_core_regular_ticket_price', '40.00'); ?>
*                <?php else: ?>
*                 SOLD OUT
*                <?php endif; ?>
*               </a>
*             </div>
*           </div>
*
*           <div class="col-xs-12 col-sm-4">
*             <div class="text-center">
*               <i class="icon fa fa-ticket fa-5x"></i>
*             </div>
*             <h2 class="text-center">Designated Driver</h2>
*
*             <p class="lead">Access to local food vendors, live music and the privilege to get your friends home safe.</p>
*
*             <div class="text-center">
*               <a href="#" 
*                  class="btn btn-danger btn-lg"
*                  disabled="disabled"
*                  data-ga-event
*                  data-ga-category="ticket_link_click"
*                  data-ga-label="homepage"
*                  data-ga-action="designated_driver">
*                  SOLD OUT
*               </a>
*             </div>
*           </div>
*
*         </div>
*       </div>
*     </div>
*
*     <div class="col-xs-12 col-sm-4">
*         <div class="text-center">
*           <i class="icon fa fa-ticket fa-5x"></i>
*         </div>
*         <h2 class="text-center">Tickets will also be available at the gate for $50</h2>
*         <p class="text-center">General Admission tickets are still available at <a href="http://appalachianmountainbrewery.com/">Appalachian Mountain Brewery</a>, <a href="http://lostprovince.com/">Lost Province</a>, <a href="http://peabodyswineandbeer.com/">Peabody's Beer and Wine</a> and <a href="http://benchmarkprovisions.com/">Benchmark Provisions</a>.</p>
*         <p>&nbsp;</p>
*
*       <div class="text-center">
*         <i class="icon fa fa-beer fa-5x"></i>
*       </div>
*       <div class="page-header">
*         <h1 class="text-center">The Festivities</h1>
*       </div>
*       <p class="text-center">Join us at the High Country Fairgrounds in Boone, North Carolina on Saturday, August 29, 2015 from 3:00pm to 7:00pm to sample a variety of craft beer, craft food, educational seminars, and live music.</p>
*     </div>
*
*   </div>
* </div>
*/ ?>
</div>

<?php if (variable_get('hcbf_breweries_week_of_message', 0) == 1): ?>
<hr />

<div class="get-there-wrapper" class="wrapper">
  <div class="container">
   <div class="row">
     <div class="col-xs-12">
       <div class="page-header">
         <h1>How will I get there and back?</h1>
       </div>
     </div>
   </div>

   <div class="row">
     <div class="col-xs-12 col-sm-6">
       <h3>Take the shuttle from campus</h3>
       <p>The folks at <a href="http://mountainalliance.org/">Mountain Alliance</a> and <a href="http://www.raftcavehike.com/">River and Earth Adventures</a> will be provided a bus service from Raley Lot on the Appalachian State University's campus to and from the event. Buses will run from 2pm until 9pm and only stop at those two locations.</p>
       <p>We have a limited amount of seating on the buses.</p>
       <iframe
         width="100%"
         height="300"
         frameborder="0" style="border:0"
         src="https://www.google.com/maps/embed/v1/place?key=AIzaSyAcBExT7Gf5b1qYZH5r_SLBMNtmsGe1O_8
         &q=Asu+Raley+Hall+Traffic+Circle+NC&zoom=13">
       </iframe>
     </div>
     <div class="col-xs-12 col-sm-6">
       <h3>Get a designated driver</h3>
       <p>This is your best bet, designated driver tickets are only $10 and can make getting to and from the festival a lot safer.</p>

       <h3>Take a taxi</h3>
       <p>Tipsy Taxi is providing FREE rides anywhere in Boone.</p>

       <h3>Get a tow</h3>
       <p>Live in Boone? Bill's will tow your car and up to 4 people anywhere within the town limits for free.</p>
     </div>
   </div>
  </div>
</div>
<?php endif; ?>

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

