<?php
/**
 * @file
 * Forms for the High Country Craft Food and Beverage Festival's volunteer functionality.
 */

/**
 * Volunteer form
 */
function hcbf_volunteer_form($form, &$form_state) {

  // Protect the form with honeypot
  honeypot_add_form_protection($form, $form_state, array('honeypot', 'time_restriction'));

  $form = array();
  $form['#attributes'] = array('role' => array('form'));

  if (variable_get('hcbf_volunteer_active', 0) == 1) {
    // The form is open for submission
    $form['info'] = array(
      '#markup' => variable_get('hcbf_volunteer_intro', 'Fill out this form to volunteer for the High Country Craft Food and Beverage Festival.'),
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );

    $form['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Your name'),
      '#required' => TRUE
    );

    $form['email'] = array(
      '#type' => 'textfield',
      '#title' => t('Email address'),
      '#required' => TRUE,
      '#rules' => array('email')
    );

    $form['date_of_birth'] = array(
      '#type' => 'date_select',
      '#title' => t('Date of birth'),
      '#required' => TRUE,
      '#date_format' => 'm/d/Y',
      '#date_label_position' => 'within',
      '#date_timezone' => 'America/New_York'
    );

    $form['shirt_size'] = array(
      '#type' => 'select',
      '#title' => t('T-shirt size'),
      '#required' => TRUE,
      '#options' => array(
        'small' => t('Small'),
        'medium' => t('Medium'),
        'large' => t('Large'),
        'x-large' => t('X-large'),
        'xx-large' => t('XX-large')
      ),
    );

    $form['previous_volunteer'] = array(
      '#type' => 'radios',
      '#title' => t('Have you volunteered before?'),
      '#required' => TRUE,
      '#options' => array(
        'no' => t('No'),
        'yes' => t('Yes'),
      ),
      '#default_value' => 'no',
    );

    $form['background'] = array(
      '#type' => 'checkboxes',
      '#title' => t('What is your background?'),
      '#required' => FALSE,
      '#options' => array(
        'brewer' => t('Brewer'),
        'enthusiast' => t('Enthusiast'),
      ),
    );

    $form['comments'] = array(
      '#type' => 'textarea',
      '#title' => t('Comments')
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Sign me up')
    );
  }
  else {
    // Message about volunteer registeration being closed
    $form['info'] = array(
      '#markup' => 'We\'re sorry but volunteer registration is closed.',
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );
  }

  return $form;
}

/**
 * Validation for the volunteer form
 */
function hcbf_volunteer_form_validate($form, &$form_state) {
  // Validate that the person attempting to volunteer is 21 or older.
  // See: http://drupalcode.org/project/validateage.git/blob/refs/heads/6.x-1.x:/validateage.module#l540
}

/**
 * Submit function for the volunteer form
 */
function hcbf_volunteer_form_submit($form, &$form_state) {
  // Sanatize the input
  // Create a volunteer node
  // Notify the responsable role a volunteer has volunteered
}

