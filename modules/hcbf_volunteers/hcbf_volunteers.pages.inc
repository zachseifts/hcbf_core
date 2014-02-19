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
    $phone_field = field_get_items('node', $volunteer, 'field_hcbf_volunteer_phone');
    $phone_value = field_view_value('node', $volunteer, 'field_hcbf_volunteer_phone', $phone_field[0]);

    $name = l(render($name_value), 'mailto:' . $email_field[0]['email'], array('absolute' => TRUE));

    $approved = array(
      '#type' => 'markup',
      '#markup' => 'Accepted',
    );
    $row_class = 'success';
    if ($volunteer->field_hcbf_volunteer_accepted['und'][0]['value'] == 'no') {
      $approved['#markup'] = 'Not accepted';
      $row_class = 'danger';
    }

    $volunteers[] = array(
      'name' => array(
        '#type' => 'markup',
        '#markup' => $name,
      ),
      'phone' => array(
        '#type' => 'markup',
        '#markup' => render($phone_value),
        '#prefix' => '<a href="tel:' . render($phone_value) . '">',
        '#suffix' => '</a>'
      ),
      'approved' => $approved,
      'view' => array(
        '#type' => 'markup',
        '#markup' => l(t('View'), 'node/' . $volunteer->nid),
      ),
      'edit' => array(
        '#type' => 'markup',
        '#markup' => l(t('Edit'), 'node/' . $volunteer->nid . '/edit', array('query' => array('destination' => 'volunteer/manage'))),
      ),
      'delete' => array(
        '#type' => 'markup',
        '#markup' => l(t('Delete'), 'node/' . $volunteer->nid . '/delete', array('query' => array('destination' => 'volunteer/manage'))),
      ),
      'row_class' => $row_class,
    );
  }

  return theme('hcbf_volunteer_manage', array('volunteers' => $volunteers));
}

