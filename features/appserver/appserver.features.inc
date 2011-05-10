<?php
/**
 * @file
 * appserver.features.inc
 */

/**
 * Implementation of hook_views_api().
 */
function appserver_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => 3.0);
  }
}

/**
 * Implementation of hook_node_info().
 */
function appserver_node_info() {
  $items = array(
    'app' => array(
      'name' => t('App'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
