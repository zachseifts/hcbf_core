<?php
/**
 * @file
 * Forms for the High Country Craft Food and Beverage Festival's brewery functionality.
 */

/**
 * Brewery registeration form
 */
function hcbf_brewery_registration_form($form, &$form_state) {

  // Protect the form with honeypot
  honeypot_add_form_protection($form, $form_state, array('honeypot', 'time_restriction'));

  $form = array();
  $form['#attributes'] = array('role' => array('form'));

  if (variable_get('hcbf_breweries_active', 0) == 1) {

    $form['info'] = array(
      '#markup' => variable_get('hcbf_breweries_intro', 'Use this form to register a brewery for the ' . variable_get('site_name', 'Drupal')),
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );

    $form['brewery_info'] = array(
      '#type' => 'fieldset',
      '#title' => t('About your brewery')
    );

    $form['brewery_info']['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Full name of the brewery'),
      '#required' => TRUE,
    );

    $form['brewery_info']['address_1'] = array(
      '#type' => 'textfield',
      '#title' => t('Address line 1'),
      '#required' => TRUE,
    );

    $form['brewery_info']['address_2'] = array(
      '#type' => 'textfield',
      '#title' => t('Address line 2'),
      '#required' => FALSE,
    );

    $form['brewery_info']['city'] = array(
      '#type' => 'textfield',
      '#title' => t('City'),
      '#required' => TRUE,
    );

    $form['brewery_info']['state'] = array(
      '#type' => 'textfield',
      '#title' => t('State'),
      '#required' => TRUE,
    );

    $form['brewery_info']['zip'] = array(
      '#type' => 'textfield',
      '#title' => t('Zip code'),
      '#required' => TRUE,
    );

    $form['brewery_info']['website'] = array(
      '#type' => 'textfield',
      '#title' => t('Brewery website'),
      '#required' => TRUE,
    );

    $form['contact_info'] = array(
      '#type' => 'fieldset',
      '#title' => t('Contact Information')
    );
    
    $form['contact_info']['contact_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Contact name'),
      '#required' => TRUE,
    );

    $form['contact_info']['primary_contact_phone'] = array(
      '#type' => 'textfield',
      '#title' => t('Primary phone number'),
      '#required' => TRUE,
    );

    $form['contact_info']['secondary_contact_phone'] = array(
      '#type' => 'textfield',
      '#title' => t('Secondary phone number'),
      '#required' => TRUE,
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Sign me up'),
      '#attributes' => array('class' => array('btn-success')),
    );
  }
  else {
    // Message about brewery registeration being closed
    $contact_link = l('contact us', 'contact');
    $message = 'We\'re sorry but brewery registration is closed. If you have any questions please ' . $contact_link . '.';
    $form['info'] = array(
      '#markup' => $message,
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );
  }

  return $form;
}

/**
 * Callback for the breweries/settings form.
 */
function hcbf_breweries_settings_form() {
  $form = array();

  $form['hcbf_breweries_active'] = array(
    '#type' => 'radios',
    '#title' => t('Is them brewery signup form active?'),
    '#default_value' => variable_get('hcbf_breweries_active', 0),
    '#options' => array(
      0 => t('No'),
      1 => t('Yes')
    ),
  );

  $form['hcbf_breweries_intro'] = array(
    '#type' => 'textarea',
    '#title' => t('Intro message'),
    '#default_value' => variable_get('hcbf_breweries_intro', ''),
    '#description' => t('This message displays on the top of the brewery signup form.')
  );

  return system_settings_form($form);
}
