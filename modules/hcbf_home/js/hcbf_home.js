(function($) {
  Drupal.behaviors.hcbf_home = {
    attach: function(context, settings) {

      // Track outbound ticket sales links.
      $('.tickets-block a.btn').each(function() {
        if (typeof ga !== 'undefined') {
          $(this).click(function(e) {
            ga('send', 'event', 'click', $(this).attr('href'));
          });
        }
      });
    }
  }
})(jQuery);
