<?php

/**
 * @file
 * Rules integration for server-side printing.
 *
 * @addtogroup rules
 * @{
 */

/**
 * Implements hook_rules_action_info().
 */
function commerce_pos_server_side_print_rules_action_info() {
  $actions = array();


  $actions['commerce_pos_server_side_print_open_cash_drawer'] = array(
    'label' => t('Open cash drawer'),
    'group' => t('Commerce POS'),
    'callbacks' => array( 'execute' => 'commerce_pos_server_side_print_rules_open_cash_drawer'),
  );

  $actions['commerce_pos_server_side_print_print_receipt'] = array(
    'label' => t('Print receipt '),
    'group' => t('Commerce POS'),
    'parameter' => array(
      'commerce_order' => array('type' => 'commerce_order', 'label' => t('Order', array(), array('context' => 'a drupal commerce order'))),
    ),
    'callbacks' => array( 'execute' => 'commerce_pos_server_side_print_rules_print_receipt'),
  );

  return $actions;
}

/**
 * Execute callback for opening the cash drawer.
 */
function commerce_pos_server_side_print_rules_open_cash_drawer($action_settings, $rule_state, $action, $callback_type) {
  commerce_pos_server_side_print_open_cash_drawer();
}

/**
 * Execute callback for printing a receipt.
 */
function commerce_pos_server_side_print_rules_print_receipt($order, $action_settings, $rule_state, $action, $callback_type) {
  $render = array(
    '#order' => $order,
    '#theme' => 'commerce_pos_server_side_print_order_receipt',
  );
  $printer_name = commerce_pos_server_side_print_printer_name();
  //Write the file.
  $filename = file_directory_temp() . '/commerce_pos_server_side_print_order_receipt.txt';
  file_put_contents($filename, drupal_render($render));
  //Send to printer.
  $command = "lpr -P $printer_name $filename";
  exec($command);
}

 /*
  * @}
  */
