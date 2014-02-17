<?php
/**
 * @file
 * Page callbacks for the High Country Craft Food and Beverage Festival's volunteer functionality.
 */

/**
 * Page callback for the breweries page.
 */
function hcbf_volunteer_manage() {

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'hcbf_volunteer')
    ->propertyOrderBy('created', 'DESC');

  $result = $query->execute();
  $volunteer_nids = array_keys($result['node']);
  $volunteer_nodes = node_load_multiple($volunteer_nids);

  $volunteers = array();
  foreach ($volunteer_nodes as $volunteer) {
    $name_field = field_get_items('node', $volunteer, 'field_hcbf_volunteer_name');
    $name_value = field_view_value('node', $volunteer, 'field_hcbf_volunteer_name', $name_field[0]);
    $email_field = field_get_items('node', $volunteer, 'field_hcbf_volunteer_email');
    $email_value = field_view_value('node', $volunteer, 'field_hcbf_volunteer_email', $email_field[0]);
    $phone_field = field_get_items('node', $volunteer, 'field_hcbf_volunteer_phone');
    $phone_value = field_view_value('node', $volunteer, 'field_hcbf_volunteer_phone', $phone_field[0]);

    $volunteers[] = array(
      'name' => array(
        '#type' => 'markup',
        '#markup' => render($name_value),
      ),
      'email' => array(
        '#type' => 'markup',
        '#markup' => render($email_value),
      ),
      'phone' => array(
        '#type' => 'markup',
        '#markup' => render($phone_value),
        '#prefix' => '<a href="tel:' . render($phone_value) . '">',
        '#suffix' => '</a>'
      ),
    );
  }

  return theme('hcbf_volunteer_manage', array('volunteers' => $volunteers));
}

