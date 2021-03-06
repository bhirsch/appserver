<?php

/**
 * @file
 *   Drush integration for appserver.
 */

/**
 * Implementation of hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and
 * description.
 *
 * Notice how this structure closely resembles how
 * you define menu hooks.
 *
 * @See drush_parse_command() for a list of recognized keys.
 *
 * @return
 *   An associative array describing your command(s).
 */
function appserver_drush_command() {
  $items = array();

  $items['appserver-make-make'] = array(
    'description' => dt('Output a .make file for designated app. Required argument: nid.'),
    'aliases' => array('amm'),
    'arguments' => array(
      'nid' => dt('Required. Node ID for selected app.'),
    ),
    'drupal dependencies' => array('appserver'),
  );
  $items['appserver-make-app'] = array(
    'description' => dt('Build a tarball for requested app. Required argument: nid.'),
    'aliases' => array('ama'),
    'arguments' => array(
      'nid' => dt('Required. Node ID for selected app.'),
    ),
    'drupal dependencies' => array('appserver'),
    'options' => array(
      '--no-tar' => 'Do not create a tarball of the app.',
      '--tar-only' => 'Only create a tarball of the app.',
      '--verbose' => 'Show drush make messages.',
    ),
  );
  $items['appserver-list-apps'] = array(
    'description' => dt('List apps'),
    'aliases' => array('ala'),
    'arguments' => array(
      'limit' => dt('Optional. Number of apps to display.'),
    ),
    'drupal dependencies' => array('appserver'),
  );

  return $items;
}

/**
 * Implementation of hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'
 *
 * @param
 *   A string with the help section (prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function appserver_drush_help($section) {
  switch ($section) {
    case 'drush:appserver-make-make':
      return dt("Output info for a .make file to build app. Required argument: nid.");
    case 'drush:appserver-make-app':
      return dt("Build a tarball for requested app. Required argument: nid.");
  }
}

/**
 * Example drush command callback.
 *
 * This is where the action takes place.
 *
 * In this function, all of Drupals API is (usually) available, including
 * any functions you have added in your own modules/themes.
 *
 * To print something to the terminal window, use drush_print().
 *
 * @param $nid
 *  Node id of an app node.
 *
 * @return $output
 *  String, text for a .make file to build the requested app.
 */
function drush_appserver_make_make($nid) {
  // Load appserver.pages.inc. We're going to grab the same
  // info that gets out put to appserver/%node/make.
  module_load_include('inc', 'appserver', 'appserver.pages');

  $node = node_load($nid);
  // If node is not an app, notify user and end.
  if ($node->type != 'app') {
    $text = "nid $nid " . dt('is not an app.');
    return drush_set_error($text);
  }
  // Node is an app. Get and return the make file.
  else {
    $output = appserver_make_page($node);
    drush_print($output);
  }
}

/**
 * @param $nid
 *  Integer. Node id of selected app.
 *
 * @param $directory
 *  String. Directory where app should go.
 *
 * @todo Check for drush_make. Give user feedback and warning if it doesn't exist.
 */
function drush_appserver_make_app($nid, $directory = NULL) {
  drush_print(dt("\n Building app. \n\n Please wait while files download... \n\n"));

  // @todo Take $directory as argument.
  $op = array();
  $op['no tar'] = drush_get_option('no-tar');
  $op['tar only'] = drush_get_option('tar-only');
  $op['verbose'] = drush_get_option('verbose');

  appserver_make_app($nid, $op);
}

/**
 * @param $limit
 *  Number of apps to return.
 *
 * @return
 *  List of apps.
 */
function drush_appserver_list_apps($limit = NULL) {
  $output = '';

  $number = ($limit) ? 'all' : $limit;
  $output .= "\n\t" . dt("App Server List $number Apps:") . "\n\n";
  $output .= "\t nid \t\t title \n";
  $output .= "\t ---- \t\t ------ \n";

  $apps = appserver_get_apps($limit);
  foreach ($apps as $app) {
    $output .= "\t $app->nid \t\t $app->title \n";
  }

  drush_print($output);
}
