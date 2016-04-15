<?php
/**
 * @file
 * Forms for the High Country Craft Food and Beverage Festival's volunteer functionality.
 */

/**
 * Volunteer form
 */
function hcbf_volunteer_form($form, &$form_state) {
  global $user;

  if ($user->uid != 0) {
    $user_wrapper = entity_metadata_wrapper('user', $user->uid);
  }

  // TODO:
  // - Check if the user already has a volunteer registration submitted.

  // Protect the form with honeypot
  honeypot_add_form_protection($form, $form_state, array('honeypot', 'time_restriction'));

  $form = array(
    '#attributes' => array('role' => array('form')),
    '#prefix' => '<div class="wrapper form-wrapper"><div class="container"><div class="row"><div class="col-xs-12">',
    '#suffix' => '</div></div></div></div>'
  );

  if (variable_get('hcbf_volunteer_registration', 0) == 1 || $user->uid == 1) {
    $form['info'] = array(
      '#markup' => 'Do you want to get involved and volunteer at the High Country Beer Fest? All you have to do is fill out this form and we\'ll get back to you with more information.',
      '#prefix' => '<p class="lead">',
      '#suffix' => '</p>',
    );

    $form['volunteer_wrapper_open'] = array(
      '#prefix' => '<div class="row">',
      '#suffix' => '<div class="col-xs-12 col-md-6">',
    );

    // The form is open for submission
    $form['account_info'] = array(
      '#type' => 'fieldset',
      '#title' => t('Account Information')
    );

    // TODO: Uncomment this in 2017 when we have users register with this for the 2nd time.
  //if (!$user_wrapper) {
  //  $form['account_info']['log_in'] = array(
  //    '#markup' => 'If you already have an account, please ' . l('login', 'user') . ' or ' . l('reset your password', 'user/password') . '.',
  //    '#prefix' => '<p>',
  //    '#suffix' => '</p>',
  //  );
  //}

    $form['account_info']['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Your name'),
      '#description' => t('Enter your full name into this field.'),
      '#required' => TRUE,
      '#attributes' => array('placeholder' => array('Your Name')),
    );
    if ($user_wrapper) {
      if ($name = $user_wrapper->field_hcbf_account_name->value()) {
        $form['account_info']['name']['#default_value'] = $name;
      }
    }

    $form['account_info']['email'] = array(
      '#type' => 'textfield',
      '#title' => t('Your email address'),
      '#description' => t('Enter an email address that we can contact you at.'),
      '#required' => TRUE,
      '#rules' => array('email'),
      '#attributes' => array('placeholder' => array('you@domain.com')),
    );

    if ($user_wrapper) {
      $form['account_info']['email']['#default_value'] = $user_wrapper->mail->value();
      $form['account_info']['email']['#disabled'] = TRUE;
    }

    $form['account_info']['phone'] = array(
      '#type' => 'textfield',
      '#title' => t('Your phone number'),
      '#description' => t('Enter a phone number where we can contact you.'),
      '#required' => TRUE,
      '#attributes' => array('placeholder' => array('(555) 555-5555')),
    );
    if ($user_wrapper) {
      if ($phone = $user_wrapper->field_hcbf_account_phone->value()) {
        $form['account_info']['phone']['#default_value'] = $phone;
      }
    }

    $form['account_info']['dob'] = array(
      '#type' => 'textfield',
      '#title' => t('Your birthday'),
      '#description' => t('Enter your date of birth. You must 21 or older to volunteer.'),
      '#required' => TRUE,
      '#attributes' => array('placeholder' => array('6/19/1985')),
    );
    if ($user_wrapper) {
      if ($dob = $user_wrapper->field_hcbf_account_dob->value()) {
        $form['account_info']['dob']['#default_value'] = $dob;
      }
    }

    $form['volunteer_wrapper_col_1_close'] = array(
      '#prefix' => '</div>',
      '#suffix' => '<div class="col-xs-12 col-md-6">',
    );

    $form['other_info'] = array(
      '#type' => 'fieldset',
      '#title' => t('Other Information')
    );

    $form['other_info']['shirt'] = array(
      '#type' => 'radios',
      '#title' => t('Your shirt size'),
      '#options' => array(
        'small' => t('Small'),
        'medium' => t('Medium'),
        'large' => t('Large'),
        'x-large' => t('X-large'),
        'xx-large' => t('XX-large')
      ),
    );

    $form['other_info']['previous_volunteer'] = array(
      '#type' => 'radios',
      '#title' => t('Have you volunteered at a this or any other beer festival before?'),
      '#options' => array(
        'no' => t('No'),
        'yes' => t('Yes'),
      ),
    );

    $form['other_info']['reference'] = array(
      '#type' => 'textfield',
      '#title' => t('References'),
      '#description' => t('Who told you about volunteering at the High Country Beer Fest?'),
    );

    $form['other_info']['comments'] = array(
      '#type' => 'textarea',
      '#title' => t('Additional information'),
      '#description' => t('Please describe your previous experience with other festivals, are you with a group, any time limitations due to other responsibilities, and any additional information.'),
    );

    $form['volunteer_wrapper_col_2_close'] = array(
      '#prefix' => '</div>',
      '#suffix' => '</div>',
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Sign me up'),
      '#attributes' => array('class' => array('btn-success')),
    );
  }
  else {
    // Message about volunteer registeration being closed
    $contact_link = l('contact us', 'contact');
    $message = 'We\'re sorry but volunteer registration is closed. If you have any questions please ' . $contact_link . '.';
    $form['info'] = array(
      '#markup' => $message,
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

  $volunteer_role = user_role_load_by_name('Volunteer');
  $current_festival = variable_get('hcbf_current_festival', 0);

  // Create the volunteer user
  $volunteer = entity_create('user', array());
  $volunteer->name = check_plain($form_state['values']['email']);
  $volunteer->mail = check_plain($form_state['values']['email']);
  $volunteer->status = 1;
  $volunteer->roles = array(
    $volunteer_role->rid => 'Volunteer',
  );
  entity_save('user', $volunteer);

  // Add extra data to the user.
  $volunteer_entity = entity_metadata_wrapper('user', $volunteer);
  $volunteer_entity->field_hcbf_account_name->set(check_plain($form_state['values']['name']));
  $volunteer_entity->field_hcbf_account_phone->set(check_plain($form_state['values']['phone']));
  $volunteer_entity->field_hcbf_account_dob->set(check_plain($form_state['values']['dob']));
//$volunteer_entity->field_hcbf_account_shirt->set(check_plain($form_state['values']['shirt']));
//$volunteer_entity->field_hcbf_account_references->set(check_plain($form_state['values']['reference']));
//$volunteer_entity->field_hcbf_account_info->set(check_plain($form_state['values']['comments']));
//$volunteer_entity->field_hcbf_account_previous->set(check_plain($form_state['values']['previous_volunteer']));
  $volunteer_entity->field_hcbf_account_accepted->set(0);
  $volunteer_entity->save();

  // Create the registration for the volunteer.
  $festival_entity = entity_metadata_wrapper('node', $current_festival);
  $volunteer_registration = entity_create('node', array(
    'type' => 'hcbf_volunteer_reg',
    'title' => $volunteer_entity->label() . ': ' . $festival_entity->label(),
    'uid' => $volunteer_entity->getIdentifier(),
  ));

  // TODO: Add fields to the registration entity for the users's shirt, references, comments, etc.
  $volunteer_registration_entity = entity_metadata_wrapper('node', $volunteer_registration);
  $volunteer_registration_entity->field_hcbf_volunteer_reg_fest->set($current_festival);
  $volunteer_registration_entity->field_hcbf_volunteer_reg_approve->set(0);
  $volunteer_registration_entity->save();

  // Redirect the user to a thank you page.
  drupal_goto('volunteer/finished');
}
