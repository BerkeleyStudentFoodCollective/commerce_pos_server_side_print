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
    'callbacks' => array( 'execute' => 'commerce_pos_server_side_print_open_cash_drawer'),
  );

  return $actions;
}

/**
 * Execute callback for opening the cash drawer.
 */
function commerce_pos_server_side_print_open_cash_drawer($action_settings, $rule_state, $action, $callback_type) {
  $printer_name = commerce_pos_server_side_print_printer_name();
  $filename = DRUPAL_ROOT . '/' . drupal_get_path('module', 'commerce_pos_server_side_print') . '/data/open.dat';
  $command = "lpr -P $printer_name -oraw $filename";
  exec($command);
  drupal_add_js(array('commercePosServerSidePrint' => array('drawerOpened' => TRUE)), 'setting');
}

 /*
  * @}
  */
