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

  $breweries = array();
  foreach ($brewery_nids as $brewery) {
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

  $breweries = array();
  foreach ($breweries_nids as $brewery) {
    $brewery_entity = entity_metadata_wrapper('node', $brewery);

    $breweries[] = array(
      'title' => array(
        '#type' => 'markup',
        '#markup' => $brewery_entity->label(),
        '#prefix' => '<h2>',
        '#suffix' => '</h2>',
      ),
      'website' => array(
        '#type' => 'markup',
        '#markup' => $brewery_entity->field_hcbf_brewery_brewery_url->value(),
        '#prefix' => '<p>',
        '#suffix' => '</p>',
      ),
    );
  }

  $breweries = array_chunk($breweries, 3);
  return theme('hcbf_breweries', array('breweries' => $breweries));
}

