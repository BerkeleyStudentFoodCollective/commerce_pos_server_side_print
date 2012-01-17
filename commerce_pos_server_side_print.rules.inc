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

  return $actions;
}

/**
 * Execute callback for opening the cash drawer.
 */
function commerce_pos_server_side_print_rules_open_cash_drawer($action_settings, $rule_state, $action, $callback_type) {
  commerce_pos_server_side_print_open_cash_drawer();
}

 /*
  * @}
  */
