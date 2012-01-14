(function ($) {

  Drupal.behaviors.commercePosServerSidePrint = {
      attach: function (context, settings) {
        if (settings.commercePosServerSidePrint && settings.commercePosServerSidePrint.drawerOpened) {
          $.getJSON(Drupal.settings.basePath + 'admin/commerce/pos/drawer_open');
          Drupal.settings.commercePosServerSidePrint.drawerOpened = false;
        }
      }
  };

})(jQuery);
