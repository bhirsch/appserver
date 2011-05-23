<?php
/**
 * @file appserver.make.inc
 *  Write app.make files and build apps with drush_make.
 *
 * @todo Note: This works by calling shell_exec(). This is sort of hackish. 
 *  Maybe we should implement a module-based version of drush_make, 
 *  then call make_make($myapp). Then the fulfill module could call call
 *  appserver_make_app($requested_app) the "normal" way.
 */

/**
 * Make app.
 * 
 * @param $nid.
 *  Node id for app node.
 * 
 *
 * @param $op
 *  array(
 *    'no replace' => TRUE/FALSE,      // don't replace existing files
 *    'no tar' => TRUE/FALSE           // don't make tarball
 *    'tar only' => TRUE/FALSE         // only create tarball (remove the other stuff)
 *    'verbose' => TRUE/FALSE, 
 *  );
 * 
 * @return $result.
 *  Array. $result = array('success' => TRUE/FALSE, 'message' => 'congrats / error message');
 *
 * TODO Enforce unique machine names for apps.
 *  - Author of app owns name space.
 *  - No other authors can create apps of same name.
 *  - Author can only create apps of same name if the version is different.
 */
function _appserver_make_app($nid, $op = array()) {
  // Set defaults.
  if (!$op) {
    $op = array(
      'no replace' => FALSE,
      'no tar' => FALSE,
      'tar only' => FALSE,
      'verbose' => TRUE,
    ); 
  }

  // If node is not an app, notify user and end.
  $node = node_load($nid);
  if ($node->type != 'app') {
    $text = "nid $nid " . t('is not an app.');
    return array('success' => FALSE, 'message' => $text);
  }

  // Write app.make file inside app directory.
  //   Load appserver.pages.inc. We're going to grab the same
  //   info that gets out put to appserver/%node/make.
  $file_contents = '';
  module_load_include('inc', 'appserver', 'appserver.pages');
  $file_contents = appserver_make_page($node);
  // Build destination URI for .make file.
  $app_name = $node->field_app_machine_name['und'][0]['safe_value'];
  $file_name = "$app_name.make";
  $path = "appserver/$app_name";
  // Get "scheme" for file storage, public or private.
  $scheme = variable_get('appserver_file_scheme', variable_get('file_default_scheme', 'public'));
  if ($scheme == 'private') {
    $uri = "$scheme://$path/$file_name";
    $destination = file_stream_wrapper_uri_normalize($uri);
  }
  else if ($scheme == 'public') {
    $destination = file_build_uri("$path/$file_name");
  }
  // If the directory doesn't exist, create it
  if (!file_prepare_directory(drupal_dirname($destination), FILE_CREATE_DIRECTORY)) {
    $text = t('The function file_prepare_directory() failed attempting to prepare a '
            . 'directory for !directory. Please notify your system administrator.', 
            array('!directory' => $path));
    return array('success' => FALSE, 'message' => $text);
  }
  // Create .make file.
  if (!$file = file_save_data($file_contents, $destination, FILE_EXISTS_REPLACE)) {
    $text = t('The function file_save_data() failed attempting to create the file: !file. '
            . 'Please notify your system administrator.', 
            array('!file' => $file_name));
    return array('success' => FALSE, 'message' => $text);
  }
  // Notify user about new file.
  //$public = new DrupalPublicStreamWrapper;
  //$file_path = $public->getDirectoryPath() . $file_path;
  $text = t('New make file created: !file',
          array('!file' => $file_name));

  // Build app by running shell_exec(drush_make).
  // Note: When shell_exec() runs here, everything is relative to the Drupal 
  // installation's root directory.
  $files_directory = variable_get('file_' . $scheme . '_path');
  $destination = "$files_directory/$path";
  $make_file = $file_name;  
  if (!$include = variable_get('appserver_drush_make_path', FALSE)) { 
    $text = t('drush_make is required for appserver to build apps. Please '
      . 'install drush_make and enter the path to drush_make here: admin/config/media/appserver.');
    return array('success' => FALSE, 'message' => $text);
  };

  // Shell commands. 
  $remove_projects = "rm -rf modules/ libraries/ themes/";
  $remove_tarball = "rm $app_name.tar.gz";
  $make_app = "drush -y make $make_file --include=$include --no-core --contrib-destination=. ";
  $make_tarball = "tar cvfz $app_name.tar.gz $app_name";
  $remove_uncompressed_files = "rm -rf $app_name";

  // Execute shell commands.
  if (!$op['no replace']) {
    shell_exec("cd $destination; $remove_projects; cd .. ; $remove_tarball;");
  }
  $output = shell_exec("cd $destination; $make_app 2>&1;");
  if (!$op['no tar']) {
    shell_exec("cd $destination; cd .. ; $make_tarball;");
  }
  if ($op['tar only'] == 'tar only') {
    shell_exec("cd $destination; cd .. ; $remove_uncompressed_files; ");
  }

  // Verify drush_make was successful. 
  // Drush returns "[ok]" or "[error]" after downloading each component in the
  // the app's .make file. If there are any errors, the last line output returns
  // "[error]".
  $start = strripos($output, '[');
  $end = strripos($output, ']');
  $length = $end - $start + 1;
  $result = substr($output, $start, $length);
  if (!$result == '[ok]') {
    // Fail. 
    $success = FALSE;
  }
  else {
    // Success!
    $success = TRUE;
  }
  // Message to user.
  if ($op['verbose']) { 
    $built = ($success) ? 'built' : 'attempted to build'; 
    $files_were_stored = ($success) ? 'Files were stored' : 'App Server attempted to store files'; 
    $text = t("App Server $built the app described in !make. \n "
            . "$files_were_stored in the !scheme file directory !file_directory. \n"
            . "Messages returned by drush_make: \n", 
            array('!make' => $make_file, '!scheme' => $scheme, '!file_directory' => $destination)
            ) . $output;    
  }
  else {
    $text = ($success) ? $app_name . t(' build successfull.') : $app_name . t(' build failed.');
  }

  // Return success/failure.
  return array('success' => $success, 'message' => $text);
}
