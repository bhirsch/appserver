<?php

/**
 * Form builder. Configure file handling for App Server.
 * 
 * This setting makes possible to store apps in the private file system
 * even if the default download method is set to public. If this is not 
 * configured, fall back on default download method for site. 
 * 
 * @ingroup forms
 * @see system_settings_form()
 */
function appserver_settings() {
  $form['appserver_file_scheme'] = array(
    '#type' => 'select',
    '#title' => t('App File Storage'),
    '#options' => array(
      'public' => t('Public'),
      'private' => t('Private'),
    ),
    '#default_value' => variable_get('appserver_file_scheme', 
                          variable_get('file_default_scheme'), 'public'),
    '#description' => t('Determine public or private file storage for Apps. '
      . 'App files are stored here: scheme://appserver/appname/appname.make '
      . 'and here: scheme://appserver/appname/appname.tar.gz, where "scheme" '
      . 'is "public" or "private", and the path to public and private files '
      . 'is set at !here.', 
      array('!here' => l('admin/config/media/file-system', 'admin/config/media/file-system'))
    ),
  );
  $form['appserver_drush_make_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to Drush Make'),
    '#default_value' => variable_get('appserver_drush_make_path', NULL),
    '#description' => t('App Server requires Drush Make to build apps. Enter the path '
                      . 'to drush_make here. This can be an absolute path like this: '
                      . '/home/username/.drush/drush_make (recommended) or path relative to '
                      . 'the root of your Drupal installation.'),
  );

  return system_settings_form($form);
}
