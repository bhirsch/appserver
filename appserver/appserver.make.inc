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
 * @return $result.
 *  Array. $result = array('success' => TRUE/FALSE, 'message' => 'congrats / error message');
 *
 * TODO Enforce unique machine names for apps.
 *  - Author of app owns name space.
 *  - No other authors can create apps of same name.
 *  - Author can only create apps of same name if the version is different.
 */
function _appserver_make_app($nid) {
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
  //   Build destination URI for .make file.
  //   @TODO revisit. Make this private.
  $app_name = $node->field_app_machine_name['und'][0]['safe_value'];
  $file_name = "$app_name.make";
  $file_path = "appserver/$app_name/$file_name";
  $destination = file_build_uri($file_path);
  // If the directory doesn't exist, create it
  if (!file_prepare_directory(drupal_dirname($destination), FILE_CREATE_DIRECTORY)) {
    $text = t('The function file_prepare_directory() failed attempting to prepare a '
            . 'directory for !directory. Please notify your system administrator.', 
            array('!directory' => $file_path));
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
  // @TODO Replace hard-coded $destination below with something that uses the File API.
  //   $file->uri = something like this: 
  //   public://appserver/ideation/ideation.make
  //   private://appserver/ideation/ideation.make
  $destination = "/home/bryan/www/apps/sites/default/files/appserver/$app_name";  
  //$make_file = "$destination/$file_name";  
  $make_file = $file_name;  
  // @TODO Replace hard-coded $include with admin setting.
  $include = '/home/bryan/.drush/drush_make';
  $drush_make = "drush -y make $make_file $app_name --include=$include --no-core --contrib-destination=. --tar";
//$output = shell_exec("cd $destination; pwd; $drush_make");
//dsm($output, 'shell exec');
  shell_exec("cd $destination; $drush_make");

  // TODO 
  // Return success/failure.
}
