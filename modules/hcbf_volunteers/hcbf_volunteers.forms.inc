<?php
/**
 * @file
 * Forms for the High Country Craft Food and Beverage Festival's volunteer functionality.
 */

/**
 * After build function for the Date of Birth field.
 */
function hcbf_format_dob($form_element, &$form_state) {
  unset($form_element['year']['#options']);

  $max_age = date('Y') - 100;
  $min_age = date('Y') - 21;
  $form_element['year']['#options'] = array();
  $form_element['year']['#options']['year'] = '-Year';
  foreach (range($min_age, $max_age) as $year){
    $form_element['year']['#options'][$year] = $year;
  }

  return $form_element;
}

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
      '#description' => t('Enter your full name.'),
      '#required' => TRUE
    );

    $form['email'] = array(
      '#type' => 'textfield',
      '#title' => t('Email address'),
      '#description' => t('Enter your email address.'),
      '#required' => TRUE,
      '#rules' => array('email')
    );

    $form['phone'] = array(
      '#type' => 'textfield',
      '#title' => t('Phone number'),
      '#description' => t('Enter your phone number.'),
      '#required' => TRUE,
    );

    $form['dob'] = array(
      '#type' => 'date_select',
      '#title' => t('Date of birth'),
      '#required' => TRUE,
      '#date_format' => 'm/d/Y',
      '#date_label_position' => 'within',
      '#date_timezone' => 'America/New_York',
      '#after_build' => array('hcbf_format_dob'),
    );

    $form['shirt'] = array(
      '#type' => 'select',
      '#title' => t('T-shirt size'),
      '#description' => t('Select your t-shirt size.'),
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

    $form['comments'] = array(
      '#type' => 'textarea',
      '#title' => t('Other comments')
    );

    $form['terms'] = array(
      '#markup' => variable_get('hcbf_volunteer_terms', 'By submitting this form you are agreeing to terms that will be expanded on.'),
      '#prefix' => '<p>',
      '#suffix' => '</p>',
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
  // Create a volunteer node
  $volunteer = entity_create('node', array('type' => 'hcbf_volunteer'));
  $volunteer_entity = entity_metadata_wrapper('node',$volunteer);
  $volunteer_entity->field_hcbf_volunteer_name = check_plain($form_state['values']['name']);
  $volunteer_entity->field_hcbf_volunteer_email = check_plain($form_state['values']['email']);
  $volunteer_entity->field_hcbf_volunteer_phone = check_plain($form_state['values']['phone']);
  $volunteer_entity->field_hcbf_volunteer_dob = check_plain($form_state['values']['dob']);
  $volunteer_entity->field_hcbf_volunteer_shirt = check_plain($form_state['values']['shirt']);
  $volunteer_entity->field_hcbf_volunteer_volunteer = check_plain($form_state['values']['previous_volunteer']);
  $volunteer_entity->field_hcbf_volunteer_comments = check_plain($form_state['values']['comments']);
  $volunteer_entity->save();

  // Notify the responsable role a volunteer has volunteered
  drupal_set_message(t('Thank you for volunteering, you will recieve an email soon with more information.'));
}

