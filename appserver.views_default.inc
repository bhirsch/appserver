<?php
/**
 * @file
 * appserver.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function appserver_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'downloadables';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Downloadables';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'References: Downloadables';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'references_style';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Core */
  $handler->display->display_options['fields']['field_downloadable_core']['id'] = 'field_downloadable_core';
  $handler->display->display_options['fields']['field_downloadable_core']['table'] = 'field_data_field_downloadable_core';
  $handler->display->display_options['fields']['field_downloadable_core']['field'] = 'field_downloadable_core';
  $handler->display->display_options['fields']['field_downloadable_core']['label'] = '';
  $handler->display->display_options['fields']['field_downloadable_core']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['text'] = '[field_downloadable_core]-';
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_downloadable_core']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_downloadable_core']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['field_api_classes'] = 0;
  /* Field: Content: Version */
  $handler->display->display_options['fields']['field_downloadable_version']['id'] = 'field_downloadable_version';
  $handler->display->display_options['fields']['field_downloadable_version']['table'] = 'field_data_field_downloadable_version';
  $handler->display->display_options['fields']['field_downloadable_version']['field'] = 'field_downloadable_version';
  $handler->display->display_options['fields']['field_downloadable_version']['label'] = '';
  $handler->display->display_options['fields']['field_downloadable_version']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_downloadable_version']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_downloadable_version']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_downloadable_version']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_downloadable_version']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_downloadable_version']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_downloadable_version']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_downloadable_version']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_downloadable_version']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_downloadable_version']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_downloadable_version']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_downloadable_version']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_downloadable_version']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_downloadable_version']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_downloadable_version']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_downloadable_version']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_downloadable_version']['field_api_classes'] = 0;
  /* Field: Content: Version */
  $handler->display->display_options['fields']['field_library_version']['id'] = 'field_library_version';
  $handler->display->display_options['fields']['field_library_version']['table'] = 'field_data_field_library_version';
  $handler->display->display_options['fields']['field_library_version']['field'] = 'field_library_version';
  $handler->display->display_options['fields']['field_library_version']['label'] = '';
  $handler->display->display_options['fields']['field_library_version']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_library_version']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_library_version']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_library_version']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_library_version']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_library_version']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_library_version']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_library_version']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_library_version']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_library_version']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_library_version']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_library_version']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_library_version']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_library_version']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_library_version']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_library_version']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_library_version']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] [field_downloadable_core][field_downloadable_version][field_library_version]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'downloadable' => 'downloadable',
    'library' => 'library',
  );

  /* Display: References: Downloadables */
  $handler = $view->new_display('references', 'References: Downloadables', 'references_1');
  $handler->display->display_options['pager']['type'] = 'some';

  /* Display: References: Libraries */
  $handler = $view->new_display('references', 'References: Libraries', 'references_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'References: Libraries';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'references_style';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Core */
  $handler->display->display_options['fields']['field_downloadable_core']['id'] = 'field_downloadable_core';
  $handler->display->display_options['fields']['field_downloadable_core']['table'] = 'field_data_field_downloadable_core';
  $handler->display->display_options['fields']['field_downloadable_core']['field'] = 'field_downloadable_core';
  $handler->display->display_options['fields']['field_downloadable_core']['label'] = '';
  $handler->display->display_options['fields']['field_downloadable_core']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['text'] = '[field_downloadable_core]-';
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_downloadable_core']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_downloadable_core']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_downloadable_core']['field_api_classes'] = 0;
  /* Field: Content: Version */
  $handler->display->display_options['fields']['field_library_version']['id'] = 'field_library_version';
  $handler->display->display_options['fields']['field_library_version']['table'] = 'field_data_field_library_version';
  $handler->display->display_options['fields']['field_library_version']['field'] = 'field_library_version';
  $handler->display->display_options['fields']['field_library_version']['label'] = '';
  $handler->display->display_options['fields']['field_library_version']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_library_version']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_library_version']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_library_version']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_library_version']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_library_version']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_library_version']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_library_version']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_library_version']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_library_version']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_library_version']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_library_version']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_library_version']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_library_version']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_library_version']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_library_version']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_library_version']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] [field_library_version]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'library' => 'library',
  );
  $translatables['downloadables'] = array(
    t('Master'),
    t('References: Downloadables'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('[field_downloadable_core]-'),
    t('[title] [field_downloadable_core][field_downloadable_version][field_library_version]'),
    t('References: Libraries'),
    t('[title] [field_library_version]'),
  );
  $export['downloadables'] = $view;

  return $export;
}
