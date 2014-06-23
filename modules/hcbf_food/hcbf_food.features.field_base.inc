<?php
/**
 * @file
 * hcbf_food.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function hcbf_food_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_hcbf_food_description'
  $field_bases['field_hcbf_food_description'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_hcbf_food_description',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_hcbf_food_image'
  $field_bases['field_hcbf_food_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_hcbf_food_image',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  return $field_bases;
}
