<?php
/**
 * @file appserver.json
 */

/**
 * @return
 *  JSON manifest for all apps available on app server. 
 * 
 * @todo It's not very efficient to load every single app separately.
 *  It's a lot of individual node_load()s, and when more than one app has the same
 *  dependency, the dependency node (downloadable or library) gets loaded multiple times.
 *  Revisit process here and optimize.
 */
function appserver_apps($distros) {
  $distros = explode(' ', $distros);
  // @TODO Get apps for requested distro(s);
  // For now, just get all app nodes available
  $nids = array();
  $results = db_query("SELECT nid FROM {node} WHERE type = 'app'")->fetchAll();
  foreach ($results as $row) {
    $nids[] = $row->nid;
  }
  $nodes = node_load_multiple($nids);

  // Get app objects.
  $apps = array();
  foreach ($nodes as $node) {
    $apps[] = appserver_get_app($node);
  }

  // Assemble manifest.
  // @todo For now, hard code Phase2's wrapper.
  $manifest = array();
  $manifest['distro'] = array(
    'distros' => 'openpublic',
    'core' => 7,
  );
  $manifest['featured app'] = 'ideation';
  $manifest['manifest version'] = '1.0';
  $manifest['apps'] = $apps;
  // Convert $manifest to JSON.
  $json = drupal_json_output($manifest);

  return $json;
}

/**
 * @param $nid
 *  Node id.
 * 
 * @return
 *  JSON manifest for individual app. 
 */
function appserver_app($nid) {
  $app = appserver_get_app($nid);
  $json = drupal_json_output($app);
  return $json;
}

/**
 * @param $n
 *  Node object for an app node.
 *  Or node id.
 * 
 * @return
 *  $app object.
 */
function appserver_get_app($n) {
  // Get $node object. 
  if (is_object($n)) {
    // $n is a $node object.
    $node = $n;
  }
  else {
    // $n is a node id.
    $node = node_load($node);
  }

  // Load referenced nodes with relevant app information.
  $downloadable = _appserver_downloadable($node);
  $dependencies = _appserver_app_dependencies($node);
  $libraries = _appserver_app_libraries($node);

  // Assemble app components.
  $app = new stdClass;
  $app->name = $node->title;
  // @todo Create a small function for each field to return a value, rather than 
  //  hard code undefined language (und) here, and to prevent annoying no index errors.
  $app->description = $node->field_app_demo_content_descript['und'][0]['safe_value'];
  $app->version = $node->field_app_version['und'][0]['safe_value'];
  $app->author = $node->field_app_author['und'][0]['safe_value'];
  $app->author_url = $node->field_app_author_url['und'][0]['safe_value'];
  // @todo Looking at Phase II's manifest, it looks like screenshots are expected 
  //  to be a numeric array. Revisit this when we get to catalog UI.
  // "screenshots" : ["http://appserver.openpublicapp.com/sites/default/files/apps/ideation-screenshot1.jpg"],
  $app->screenshots = $node->field_app_screenshots['und'][0]['safe_value'];
  $app->logo = $node->field_app_logo['und'][0]['safe_value'];
  $app->machine_name = $node->field_app_machine_name['und'][0]['safe_value'];
  $app->downloadable = $downloadable['list'];
  $app->dependencies = $dependencies['list'];
  $app->libraries = $libraries['list'];
  $app->downloadables = array_merge($downloadable['urls'], $dependencies['urls'], $libraries['urls']);

  return $app;
}

/**
 * @param $node
 *  Node object, app node.
 * 
 * @return
 *  $dependencies, array of dependencies.
 *  E.g.
 *  $dependencies['list']['views'] = 'views 7.x-1.0';
 *  $dependencies['list']['votingapi'] = 'votingapi 7.x-2.4';
 *  $dependencies['urls']['views 7.x-2.4'] = 'http://path/to/download';
 *  $dependencies['urls']['votingapi 7.x-2.4'] = 'http://... ';
 */
function _appserver_app_dependencies($node) {
  $nodes = _appserver_get_referenced_nodes($node, 'field_app_dependencies');
  $output = array();

  foreach ($nodes as $node) {
    $name = $node->title;
    $core = $node->field_downloadable_core['und'][0]['value'];
    $version = $node->field_downloadable_version['und'][0]['safe_value'];
    $full_name = "$name $core-$version";
    $output['list'][$name] = $full_name;
    $output['urls'][$full_name] = $node->field_downloadable_url['und'][0]['safe_value'];
  } 

  return $output;
}

/**
 * @param $node
 *  Node object, app node.
 * 
 * @return
 *  $libraries, array of library dependencies.
 *  E.g.
 *  $output['openlayers_slim'] = 'openlayers_slim 1.7';
 */
function _appserver_app_libraries($node) {
  $nodes = _appserver_get_referenced_nodes($node, 'field_app_libraries');
  $output = array();

  foreach ($nodes as $node) {
    $name = $node->title;
    $version = $node->field_library_version['und'][0]['safe_value'];
    $full_name = "$name $version";
    $output['list'][$name] = $full_name;
    $output['urls'][$full_name] = $node->field_library_url['und'][0]['safe_value'];
  } 

  return $output;
}

/** 
 * @param $node
 *  Node object for an app node.
 *
 * @param $field
 *  Field name, e.g. 'field_app_dependencies'
 * 
 * @return $nodes
 *  Array of node objects.
 */
function _appserver_get_referenced_nodes($node, $field) {
  $nodes = array();
  $nids = array(); 

  foreach ($node->$field as $items) {
    foreach($items as $item) {
      $nids[] = $item['nid'];
    }
  }
 $nodes = node_load_multiple($nids);

  return $nodes;
}

/**
 * @param $node
 *  Node object, app node.
 *
 * @return 
 *  Array. 
 *  $downloadable['list'] = 'name 7.x-1.0 alpha';
 *  $downloadable['urls'] = array('name 7.x-1.0 alpha' => 'http://path/to/download');
 */
function _appserver_downloadable($node) {
  $nodes = _appserver_get_referenced_nodes($node, 'field_app_downloadable');
  $output = array();

  // @todo Add test here. count($nodes) should be 1.
  foreach ($nodes as $node) {
    $name = $node->title;
    $core = $node->field_downloadable_core['und'][0]['value'];
    $version = $node->field_downloadable_version['und'][0]['safe_value'];
    $full_name = "$name $core-$version";
    $output['list'] = $full_name;
    $output['urls'][$full_name] = $node->field_downloadable_url['und'][0]['safe_value'];
  } 

  return $output;
}
