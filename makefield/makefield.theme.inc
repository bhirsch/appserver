<?php
/**
 * @file makefield.theme.inc
 */
/**
 * Returns HTML for a makefield_formatter
 */
function theme_makefield_default_formatter($variables) {
  $item = $variables['item'];
  $output = makefield_makify($item);
  
  $output = check_markup($output);

  return $output;
}

/**
 * This function "makifies" an array, formatting it like a .make file. 
 * 
 * @param $components
 *  Array, components for a project or library in a .make file.
 * 
 * @return
 *  String.
 */
function makefield_makify($components) {
  $output = ''; 
  $type = ($components['project_type'] == 'project') ? 'projects' : 'libraries';
  $name = $components['name'];

  foreach ($components as $component => $value) {
    if (!empty($value)) {
      switch ($component) {
        case 'version':
          $output .= $type . '[' . $name . '] = ' . $value . "\n";
        break;

        case 'subdir':
          $output .= $type . '[' . $name . '][subdir] = ' . $value . " \n";
        break;

        case 'location':
          $output .= $type . '[' . $name . '][location] = ' . $value . " \n";
        break;

        case 'type':
          $output .= $type . '[' . $name . '][type] = ' . $value . " \n";
        break;

        case 'directory_name':
          $output .= $type . '[' . $name . '][directory_name] = ' . $value . " \n";
        break;

        case 'l10n_path':
          $output .= $type . '[' . $name . '][l10n_path] = ' . $value . " \n";
        break;

        case 'l10n_url':
          $output .= $type . '[' . $name . '][l10n_url] = ' . $value . " \n";
        break;

        case 'download_type':
          $output .= $type . '[' . $name . '][download][type] = ' . $value . " \n";
        break;

        case 'download_url':
          $output .= $type . '[' . $name . '][download][url] = ' . $value . " \n";
        break;

        case 'download_checksum_value':
          $checksum = $components['download_checksum_type'];
          $output .= $type . '[' . $name . '][download][' . $checksum .'] = ' . $value . " \n";
        break;

        case 'request_type':
          $output .=  $type . '[' . $name . '][download][request_type] = ' . $value . "\n";
        break;

        case 'data':
          $output .=  $type . '[' . $name . '][download][data] = ' . $value . "\n";
        break;

        case 'filename':
          $output .=  $type . '[' . $name . '][download][filename] = ' . $value . "\n";
        break;

        case 'date':
          $output .=  $type . '[' . $name . '][download][date] = ' . $value . "\n";
        break;

        case 'root':
          $output .=  $type . '[' . $name . '][download][root] = ' . $value . "\n";
        break;

        case 'module':
          $output .=  $type . '[' . $name . '][download][module] = ' . $value . "\n";
        break;

        case 'revision':
          $output .=  $type . '[' . $name . '][download][revision] = ' . $value . "\n";
        break;

        case 'branch':
          $output .=  $type . '[' . $name . '][download][branch] = ' . $value . "\n";
        break;

        case 'tag':
          $output .=  $type . '[' . $name . '][download][tag] = ' . $value . "\n";
        break;

        case 'interactive':
          $output .=  $type . '[' . $name . '][download][interactive] = ' . $value . "\n";
        break;

        case 'username':
          $output .=  $type . '[' . $name . '][download][username] = ' . $value . "\n";
        break;

        case 'password':
          $output .=  $type . '[' . $name . '][download][password] = ' . $value . "\n";
        break;

        case 'patch_url':
          $output .=  $type . '[' . $name . '][patch][url] = ' . $value . "\n";
        break;

        case 'patch_md5':
          $output .=  $type . '[' . $name . '][patch][md5] = ' . $value . "\n";
        break;

        case 'library_destination':
          $output .=  $type . '[' . $name . '][destination] = ' . $value . "\n";
        break;
      }
    }
  }
  $output .= "\n";

  return $output;
}
