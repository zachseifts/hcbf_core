<?php
/**
 * @file
 * hcbf_breweries.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function hcbf_breweries_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-hcbf_brewery-field_hcbf_brewery_location'
  $field_instances['node-hcbf_brewery-field_hcbf_brewery_location'] = array(
    'bundle' => 'hcbf_brewery',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The location of this brewery.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hcbf_brewery_location',
    'label' => 'Location',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -2,
    ),
  );

  // Exported field_instance: 'node-hcbf_brewery-field_hcbf_brewery_name'
  $field_instances['node-hcbf_brewery-field_hcbf_brewery_name'] = array(
    'bundle' => 'hcbf_brewery',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The name of the brewery.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hcbf_brewery_name',
    'label' => 'Name',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -3,
    ),
  );

  // Exported field_instance: 'node-hcbf_brewery-field_hcbf_brewery_website'
  $field_instances['node-hcbf_brewery-field_hcbf_brewery_website'] = array(
    'bundle' => 'hcbf_brewery',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A link to this breweries website.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hcbf_brewery_website',
    'label' => 'Website',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => -1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('A link to this breweries website.');
  t('Location');
  t('Name');
  t('The location of this brewery.');
  t('The name of the brewery.');
  t('Website');

  return $field_instances;
}
