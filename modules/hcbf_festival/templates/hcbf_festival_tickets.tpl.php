<?php
/**
 * @file
 * A template for the buy tickets box.
 */
?>

<div class="buy-tickets-wrapper">
  <div class="text-center">
    <i class="icon fa fa-ticket fa-5x"></i>
  </div>

  <div class="page-header">
    <h2 class="text-center">Buy Tickets</h2>
  </div>
  
  <?php if (variable_get('hcbf_core_on_sale', 0) != 1): ?>
    <p class="lead text-center">Tickets will be on sale soon!</p>
  <?php else: ?>
    <p class="lead">Tickets will also be available at the gate for $50.</p>
    <p>General Admission tickets are still available at <a href="http://appalachianmountainbrewery.com/">Appalachian Mountain Brewery</a>, <a href="http://lostprovince.com/">Lost Province</a>, <a href="http://peabodyswineandbeer.com/">Peabody's Beer and Wine</a> and <a href="http://benchmarkprovisions.com/">Benchmark Provisions</a>.</p>
    <div class="table-responsive">
      <table class="table ticket-table">
        <tbody>
          <tr>
            <td>General Admission</td>
            <td>
              <?php if (variable_get('hcbf_core_regular_ticket_sold_out', 0) == 0): ?>
              <a href="<?php print variable_get('hcbf_core_regular_ticket_link', '#'); ?>"
                 class="btn btn-success btn-sm"
              <?php else: ?>
              <a href="#"
                 class="btn btn-danger btn-sm"
                 disabled="disabled"
               <?php endif; ?>
                 data-ga-event
                 data-ga-category="ticket_link_click"
                 data-ga-label="block-ticket"
                 data-ga-action="general_admission">
                 <?php if (variable_get('hcbf_core_regular_ticket_sold_out', 0) == 0): ?>
                  $<?php print variable_get('hcbf_core_regular_ticket_price', '40.00'); ?>
                 <?php else: ?>
                  SOLD OUT
                 <?php endif; ?>
              </a>
            </td>
          </tr>
          <tr>
            <td>VIP</td>
            <td>
              <a href="<?php print variable_get('hcbf_core_vip_ticket_link', '#'); ?>"
                 class="btn btn-success btn-sm"
                 data-ga-event
                 data-ga-category="ticket_link_click"
                 data-ga-label="block-ticket"
                 data-ga-action="vip">
                $<?php print variable_get('hcbf_core_vip_ticket_price', '80.00'); ?>
              </a>
            </td>
          </tr>
          <tr>
            <td>Designated Driver</td>
            <td>
              <a href="<?php print variable_get('hcbf_core_dd_ticket_link', '#'); ?>"
                 class="btn btn-success btn-sm"
                 data-ga-event
                 data-ga-category="ticket_link_click"
                 data-ga-label="block-ticket"
                 data-ga-action="designated_driver">
                $<?php print variable_get('hcbf_core_dd_ticket_price', '10.00'); ?>
              </a>
            </td>
          </tr>
        </tbody>
      </table>
    </div>
  <?php endif; ?>

  <?php // TODO: Remove this hacky line soon. ?>
  <p>&nbsp;</p>
  
</div>

