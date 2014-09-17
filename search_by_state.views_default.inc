<?php
/**
 * @file
 * search_by_state.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function search_by_state_views_default_views() {
  $views = array();

  // Exported view: listings_by_state
  $view = new view();
  $view->name = 'listings_by_state';
  $view->description = 'Boondocking Listings by State';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'listings_by_state';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Boondocking Locations';
  $handler->display->display_options['css_class'] = 'search-results';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['type'] = 'ol';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['php_output'] = '<?php dd($view); dd($handler); dd($results); ?>

<p>There are currently <?php print $view->total_rows; ?> RV boondocking locations in <?php $provname = location_province_name($view->args[0], $view->args[1]); if (!empty($provname)) { print $provname; } else {print location_country_name($view->args[0]);} ?>. </p><p>Click on a marker to see the name of the member and link to their profile. Double click on an unmarked area to zoom in.</p>';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  /* Relationship: Profile: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['required'] = TRUE;
  /* Relationship: Profile: Your Location (field_boondock_location) */
  $handler->display->display_options['relationships']['field_boondock_location_lid']['id'] = 'field_boondock_location_lid';
  $handler->display->display_options['relationships']['field_boondock_location_lid']['table'] = 'field_data_field_boondock_location';
  $handler->display->display_options['relationships']['field_boondock_location_lid']['field'] = 'field_boondock_location_lid';
  $handler->display->display_options['relationships']['field_boondock_location_lid']['required'] = TRUE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'user';
  $handler->display->display_options['relationships']['profile']['label'] = 'User Profile';
  $handler->display->display_options['relationships']['profile']['required'] = TRUE;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'profile' => 'profile',
  );
  /* Field: Profile: User Photo */
  $handler->display->display_options['fields']['field_user_photo']['id'] = 'field_user_photo';
  $handler->display->display_options['fields']['field_user_photo']['table'] = 'field_data_field_user_photo';
  $handler->display->display_options['fields']['field_user_photo']['field'] = 'field_user_photo';
  $handler->display->display_options['fields']['field_user_photo']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_photo']['label'] = '';
  $handler->display->display_options['fields']['field_user_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_photo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Location: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'location';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['relationship'] = 'field_boondock_location_lid';
  $handler->display->display_options['fields']['city']['exclude'] = TRUE;
  /* Field: Location: Province */
  $handler->display->display_options['fields']['province']['id'] = 'province';
  $handler->display->display_options['fields']['province']['table'] = 'location';
  $handler->display->display_options['fields']['province']['field'] = 'province';
  $handler->display->display_options['fields']['province']['relationship'] = 'field_boondock_location_lid';
  $handler->display->display_options['fields']['province']['label'] = '';
  $handler->display->display_options['fields']['province']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['province']['alter']['text'] = '[city], [province]';
  $handler->display->display_options['fields']['province']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['province']['empty'] = '[city]';
  /* Sort criterion: Location: Longitude */
  $handler->display->display_options['sorts']['longitude']['id'] = 'longitude';
  $handler->display->display_options['sorts']['longitude']['table'] = 'location';
  $handler->display->display_options['sorts']['longitude']['field'] = 'longitude';
  $handler->display->display_options['sorts']['longitude']['relationship'] = 'field_boondock_location_lid';
  /* Sort criterion: Location: Latitude */
  $handler->display->display_options['sorts']['latitude']['id'] = 'latitude';
  $handler->display->display_options['sorts']['latitude']['table'] = 'location';
  $handler->display->display_options['sorts']['latitude']['field'] = 'latitude';
  $handler->display->display_options['sorts']['latitude']['relationship'] = 'field_boondock_location_lid';
  /* Contextual filter: Location: Country */
  $handler->display->display_options['arguments']['country']['id'] = 'country';
  $handler->display->display_options['arguments']['country']['table'] = 'location';
  $handler->display->display_options['arguments']['country']['field'] = 'country';
  $handler->display->display_options['arguments']['country']['relationship'] = 'field_boondock_location_lid';
  $handler->display->display_options['arguments']['country']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['country']['title'] = '%1 Boondocking Locations';
  $handler->display->display_options['arguments']['country']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['country']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['country']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['country']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Location: Province */
  $handler->display->display_options['arguments']['province']['id'] = 'province';
  $handler->display->display_options['arguments']['province']['table'] = 'location';
  $handler->display->display_options['arguments']['province']['field'] = 'province';
  $handler->display->display_options['arguments']['province']['relationship'] = 'field_boondock_location_lid';
  $handler->display->display_options['arguments']['province']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['province']['title'] = '%2, %1 Boondocking Locations';
  $handler->display->display_options['arguments']['province']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['province']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['province']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['province']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['province']['break_phrase'] = 0;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'boondocking_available' => 'boondocking_available',
  );
  /* Filter criterion: Profile: Do you have a boondocking location available on your property? (field_ba_bda_pref) */
  $handler->display->display_options['filters']['field_ba_bda_pref_value']['id'] = 'field_ba_bda_pref_value';
  $handler->display->display_options['filters']['field_ba_bda_pref_value']['table'] = 'field_data_field_ba_bda_pref';
  $handler->display->display_options['filters']['field_ba_bda_pref_value']['field'] = 'field_ba_bda_pref_value';
  $handler->display->display_options['filters']['field_ba_bda_pref_value']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'user';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'user';
  $handler->display->display_options['filters']['rid']['value'] = array(
    8 => '8',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'SearchByState';

  /* Display: Map Attachment */
  $handler = $view->new_display('attachment', 'Map Attachment', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'gmap';
  $handler->display->display_options['style_options']['macro'] = '[gmap width=100% | height=600px]';
  $handler->display->display_options['style_options']['markertype'] = 'numbers';
  $handler->display->display_options['style_options']['latfield'] = 'field_user_photo';
  $handler->display->display_options['style_options']['lonfield'] = 'field_user_photo';
  $handler->display->display_options['style_options']['markerfield'] = 'name';
  $handler->display->display_options['style_options']['geofield'] = 'field_user_photo';
  $handler->display->display_options['style_options']['enablermt'] = 0;
  $handler->display->display_options['style_options']['rmtfield'] = 'field_user_photo';
  $handler->display->display_options['style_options']['center_on_nodearg_arg'] = 'country';
  $handler->display->display_options['style_options']['animation'] = '2';
  $handler->display->display_options['style_options']['highlight_nodearg_arg'] = 'country';
  $handler->display->display_options['style_options']['autoclick_on_nodearg_arg'] = 'country';
  $handler->display->display_options['style_options']['tooltipfield'] = 'name';
  $handler->display->display_options['style_options']['bubbletextfield'] = 'name';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry, there are no locations in the state/country you specified.';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['inherit_pager'] = TRUE;

  $views[$view->name] = $view;

  // Exported view: statelisting
  $view = new view();
  $view->name = 'statelisting';
  $view->description = 'Alphabetic List of States with Boondocking Locations';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'StateListing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Boondocking Locations by State';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'country',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Below you\'ll find a listing of all of our boondocking locations by country and state. For more detailed search capabilities including the ability to filter based on rig size, etc, please see our <a href=\'/search-boondocking-by-location\'>search by location</a> page.';
  $handler->display->display_options['header']['area']['format'] = '1';
  /* Relationship: Profile: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Relationship: Profile: Your Location (field_boondock_location) */
  $handler->display->display_options['relationships']['field_boondock_location_lid']['id'] = 'field_boondock_location_lid';
  $handler->display->display_options['relationships']['field_boondock_location_lid']['table'] = 'field_data_field_boondock_location';
  $handler->display->display_options['relationships']['field_boondock_location_lid']['field'] = 'field_boondock_location_lid';
  $handler->display->display_options['relationships']['field_boondock_location_lid']['required'] = TRUE;
  /* Field: Location: Country */
  $handler->display->display_options['fields']['country_1']['id'] = 'country_1';
  $handler->display->display_options['fields']['country_1']['table'] = 'location';
  $handler->display->display_options['fields']['country_1']['field'] = 'country';
  $handler->display->display_options['fields']['country_1']['relationship'] = 'field_boondock_location_lid';
  $handler->display->display_options['fields']['country_1']['label'] = 'country-shortcode';
  $handler->display->display_options['fields']['country_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['country_1']['style'] = 'code';
  /* Field: Location: Province */
  $handler->display->display_options['fields']['province_1']['id'] = 'province_1';
  $handler->display->display_options['fields']['province_1']['table'] = 'location';
  $handler->display->display_options['fields']['province_1']['field'] = 'province';
  $handler->display->display_options['fields']['province_1']['relationship'] = 'field_boondock_location_lid';
  $handler->display->display_options['fields']['province_1']['label'] = 'province-shortcode';
  $handler->display->display_options['fields']['province_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['province_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['province_1']['style'] = 'code';
  /* Field: Location: Country */
  $handler->display->display_options['fields']['country']['id'] = 'country';
  $handler->display->display_options['fields']['country']['table'] = 'location';
  $handler->display->display_options['fields']['country']['field'] = 'country';
  $handler->display->display_options['fields']['country']['relationship'] = 'field_boondock_location_lid';
  $handler->display->display_options['fields']['country']['label'] = '';
  $handler->display->display_options['fields']['country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['country']['element_label_colon'] = FALSE;
  /* Field: Location: Province */
  $handler->display->display_options['fields']['province']['id'] = 'province';
  $handler->display->display_options['fields']['province']['table'] = 'location';
  $handler->display->display_options['fields']['province']['field'] = 'province';
  $handler->display->display_options['fields']['province']['relationship'] = 'field_boondock_location_lid';
  $handler->display->display_options['fields']['province']['label'] = '';
  $handler->display->display_options['fields']['province']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['province']['alter']['path'] = 'SearchByState/[country_1]/[province_1]';
  $handler->display->display_options['fields']['province']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['province']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['province']['empty'] = '<a href="/SearchByState/[country_1]">No State Availalbe</a>';
  /* Sort criterion: Location: Country */
  $handler->display->display_options['sorts']['country']['id'] = 'country';
  $handler->display->display_options['sorts']['country']['table'] = 'location';
  $handler->display->display_options['sorts']['country']['field'] = 'country';
  $handler->display->display_options['sorts']['country']['relationship'] = 'field_boondock_location_lid';
  /* Sort criterion: Location: Province */
  $handler->display->display_options['sorts']['province']['id'] = 'province';
  $handler->display->display_options['sorts']['province']['table'] = 'location';
  $handler->display->display_options['sorts']['province']['field'] = 'province';
  $handler->display->display_options['sorts']['province']['relationship'] = 'field_boondock_location_lid';
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'boondocking_available' => 'boondocking_available',
  );
  /* Filter criterion: Profile: Do you have a boondocking location available on your property? (field_ba_bda_pref) */
  $handler->display->display_options['filters']['field_ba_bda_pref_value']['id'] = 'field_ba_bda_pref_value';
  $handler->display->display_options['filters']['field_ba_bda_pref_value']['table'] = 'field_data_field_ba_bda_pref';
  $handler->display->display_options['filters']['field_ba_bda_pref_value']['field'] = 'field_ba_bda_pref_value';
  $handler->display->display_options['filters']['field_ba_bda_pref_value']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'user';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'user';
  $handler->display->display_options['filters']['rid']['value'] = array(
    8 => '8',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'statelisting';

  $views[$view->name] = $view;

  return $views;
}
