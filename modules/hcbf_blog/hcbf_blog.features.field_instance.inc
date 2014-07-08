<?php
/**
 * @file
 * hcbf_blog.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function hcbf_blog_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-hcbf_post-field_hcbf_post_body'
  $field_instances['node-hcbf_post-field_hcbf_post_body'] = array(
    'bundle' => 'hcbf_post',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hcbf_post_body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => -4,
    ),
  );

  // Exported field_instance: 'node-hcbf_post-field_hcbf_post_tags'
  $field_instances['node-hcbf_post-field_hcbf_post_tags'] = array(
    'bundle' => 'hcbf_post',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the tags for this post.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
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
    'field_name' => 'field_hcbf_post_tags',
    'label' => 'Tags',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => -3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Select the tags for this post.');
  t('Tags');

  return $field_instances;
}
