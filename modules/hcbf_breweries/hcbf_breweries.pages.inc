<?php
/**
 * @file
 * Page callbacks for the High Country Craft Food and Beverage Festival's brewery functionality.
 */

/**
 * Page callback for the breweries page.
 */
function hcbf_breweries_manage() {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'hcbf_brewery')
    ->propertyOrderBy('created', 'DESC');

  $result = $query->execute();
  $brewery_nids = array_keys($result['node']);
  $brewery_nodes = node_load_multiple($brewery_nids);

  $breweries = array();
  
  foreach ($brewery_nodes as $brewery) {
    $brewery_entity = entity_metadata_wrapper('node', $brewery);

    $breweries[] = array(
      'name' => array(
        '#type' => 'markup',
        '#markup' => $brewery_entity->label(),
      ),
    );
  };

  return theme('hcbf_breweries_manage', array('breweries' => $breweries));
}


/**
 * Page callback for the breweries page.
 */
function hcbf_breweries() {
  // Get all of the published breweries.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'hcbf_brewery')
    ->propertyCondition('status', 1)
    ->propertyOrderBy('created', 'DESC');

  $result = $query->execute();
  $breweries_nids = array_keys($result['node']);
  $breweries_nodes = node_load_multiple($breweries_nids);

  $breweries = array();
  foreach ($breweries_nodes as $brewery) {

    $location_field = field_get_items('node', $brewery, 'field_hcbf_brewery_location');
    $location_value = field_view_value('node', $brewery, 'field_hcbf_brewery_location', $location_field[0]);

    $website_field = field_get_items('node', $brewery, 'field_hcbf_brewery_website');
    $website_value = field_view_value('node', $brewery, 'field_hcbf_brewery_website', $website_field[0]);

    $breweries[] = array(
      'title' => array(
        '#type' => 'markup',
        '#markup' => $brewery->title,
        '#prefix' => '<h2>',
        '#suffix' => '</h2>',
      ),
      'location' => array(
        '#type' => 'markup',
        '#markup' => render($location_value),
        '#prefix' => '<p>',
        '#suffix' => '</p>',
      ),
      'website' => array(
        '#type' => 'markup',
        '#markup' => render($website_value),
        '#prefix' => '<p>',
        '#suffix' => '</p>',
      ),
    );
  }

  $breweries = array_chunk($breweries, 3);
  return theme('hcbf_breweries', array('breweries' => $breweries));
}

