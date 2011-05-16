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
