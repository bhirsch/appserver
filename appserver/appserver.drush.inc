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

  $items['appserver-make'] = array(
    'callback' => 'appserver_drush_make',
    'description' => dt('Output make file for designated app.'),
    'aliases' => array('apmk'),
    'arguments' => array(
      'nid' => dt('Required. Node ID for selected app.'),
    ),
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
    case 'drush:appserver-make':
      return dt("Output info for a .make file to build app.");
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
function appserver_drush_make($nid) {
  // Load appserver.pages.inc. We're going to grab the same 
  // info that gets out put to appserver/%node/make.
  module_load_include('inc', 'appserver', 'appserver.pages');

  $node = node_load($nid);
  // If node is not an app, notify user and end.
  if ($node->type != 'app') {
    $text = "nid $nid " . dt('is not an app.');
    drush_print($text);
  }
  // Node is an app. Get and return the make file.
  else {
    $output = appserver_make_page($node);
    drush_print($output);
  }
}