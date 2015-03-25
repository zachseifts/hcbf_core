<?php
/**
 * @file
 * The admin pages and forms for the High Country Beer Fest site's admin pages.
 */

function hcbf_core_admin() {
  $form = array();

  $form['core'] = array(
    '#type' => 'fieldset',
    '#title' => 'HCBF core options',
  );

  $form['core']['hcbf_core_on_sale'] = array(
    '#type' => 'select',
    '#title' => t('Are tickets on sale?'),
    '#default_value' => variable_get('hcbf_core_on_sale', 0),
    '#options' => array(
      0 => 'No',
      1 => 'Yes',
    ),
    '#description' => t('Are ticketes on sale?'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
