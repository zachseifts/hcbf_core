<?php
/**
 * @file
 * The admin pages and forms for the High Country Beer Fest site's volunteer admin pages.
 */

/**
 * Callback for the volunteers listing page.
 */
function hcbf_volunteers_listing() {

  $current_festival = variable_get('hcbf_current_festival', 0);
  $volunteer_role = user_role_load_by_name('Volunteer');

  $user_query = new EntityFieldQuery();
  $user_query->entityCondition('entity_type', 'user')
    ->fieldCondition('field_hcbf_account_festival', 'target_id', $current_festival);
  $user_result = $user_query->execute();

  $volunteers = array();
  if (!empty($user_result)) {
    $user_uids = array_keys($user_result['user']);
    $users = user_load_multiple($user_uids);

    foreach ($user_uids as $user_id) {
      $user = entity_metadata_wrapper('user', $user_id);
      if ($user) {
        $volunteers[] = $user;
      }
    }
  }

  return theme('hcbf_volunteers_listing', array('volunteers' => $volunteers));
}
