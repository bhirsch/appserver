<?php
/**
 * @file
 * appserver.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function appserver_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_author|node|app|form';
  $field_group->group_name = 'group_author';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'app';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Author Info',
    'weight' => '5',
    'children' => array(
      0 => 'field_app_author',
      1 => 'field_app_author_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Author Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_author|node|app|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_components|node|app|form';
  $field_group->group_name = 'group_components';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'app';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Components',
    'weight' => '9',
    'children' => array(
      0 => 'field_app_makefield',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Components',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_components|node|app|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_distros|node|app|form';
  $field_group->group_name = 'group_distros';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'app';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Recommended Distributions',
    'weight' => '4',
    'children' => array(
      0 => 'field_app_distro',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Recommended Distributions',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_distros|node|app|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_uploads|node|app|form';
  $field_group->group_name = 'group_uploads';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'app';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Uploads (Attached Files)',
    'weight' => '8',
    'children' => array(
      0 => 'field_app_logo',
      1 => 'field_app_screenshots',
      2 => 'field_app_files',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Uploads (Attached Files)',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_uploads|node|app|form'] = $field_group;

  return $export;
}
