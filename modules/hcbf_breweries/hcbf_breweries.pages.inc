<?php
/**
 * @file
 * Page callbacks for the High Country Craft Food and Beverage Festival's brewery functionality.
 */

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
    $breweries[] = array(
      'title' => array(
        '#type' => 'markup',
        '#markup' => $brewery->title,
        '#prefix' => '<h2>',
        '#suffix' => '</h2>',
      ),
    );
  }

  $breweries = array_chunk($breweries, 3);
  return theme('hcbf_breweries', array('breweries' => $breweries));
}

