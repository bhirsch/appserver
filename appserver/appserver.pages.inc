<?php 
/**
 * @file appserver.page.inc
 */

/**
 * Callback for appserver/%node/make/%.
 * 
 * @param $node
 *  $node object.
 *
 * @param $op
 *  String. Optional. If $op = 'html' send back markup.
 */
function appserver_make_page($node, $op = NULL) {
  $output = '';

  // Abort if node is not an app.
  if (!$node->type == 'app'){
    return t("Node $node->nid is not an app.");
  }

  drupal_set_title(t($node->title));

  // Load makefield.theme.inc so we can call makefield_makify().
  module_load_include('inc', 'makefield', 'makefield.theme');
  $language = $node->language;
//dsm($node);
  $title = check_plain($node->title);
  $name = $node->field_app_machine_name[$language][0]['safe_value'];
  $core = $node->field_app_core[$language][0]['value'];
  $version = $node->field_app_version[$language][0]['value'];
  // Prepare general app info.
  $output .= "; $title \n"; 
  $output .= "; ---------------------------- \n";
  $output .= "; $name $core.x-$version \n\n";
  $output .= "; Core \n";
  $output .= "; ------ \n";
  $output .= "core = $core.x \n\n";
  $output .= "; API version \n";
  $output .= "; ------------ \n";
  $output .= "api = 2 \n\n";
  // */
  // Prepare app components (makify make fields).
  foreach ($node->field_app_makefield[$language] as $makefield) {
    $output .= makefield_makify($makefield);
  }

  if ($op == 'html') {
    $output = check_markup($output);
  }

  return $output;
}

/**
 * Callback for appserver/listview.
 * This page gets themed by page--appserver--listview.tpl.php.
 *
 * @TODO page--appserver--listview.tpl.php currently lives in the theme: appjqm.
 *  Commit the theme and/or move .tpl.php into module.
 * 
 * @todo Add pager. This will crash eventually with too many apps displaying at once.
 * 
 * @return
 *  $build, render array
 */
function appserver_listview_page() {
  $results = db_query("SELECT nid FROM {node} WHERE type = 'app' AND status = 1")->fetchAll();
  $nids = array();
  foreach ($results as $row) {
    $nids[] = $row->nid;
  }
  $nodes = node_load_multiple($nids);

  //@todo Create a custom view mode
  // $view_mode = 'app_catalog';
  //$build = node_view_multiple($nodes, $view_mode);
//$build = node_view_multiple($nodes);
//dsm($build, 'build');

  // Build a jquerymobile render array including a
  // a pages array, page arrays, and listview array.
  $pages = array();
  // The first jquerymobile page is an unordered list, (data-role=listview).
  $pages[0] = array(
    //'#theme' => 'jquerymobile_page',
    'id' => 'catalog',
    'contents' => array(
      '#theme' => 'jquerymobile_listview',  
      'items' => array(),
    ),
  );
  // Each app node gets a list item and a dedicated jquerymobile page.
  foreach ($nodes as $node) {
    $id = 'app-' . $node->nid;
    // List item: 
    $pages[0]['contents']['items'][] = array(
      'node' => $node,
      'link to' => $id,
    );
    // Dedicated jquerymobile page: 
    $content = array(
     // '#theme' => 'jquerymobile_page',
      'node' => $node,  
    );
    $pages[] = $content;
  }
  $build = array(
    '#theme' => 'jquerymobile_pages',
    'pages' => $pages,
  );
dsm($build, 'jquery build');

  return $build;
}
