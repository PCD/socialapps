<?php
function socialappsm_block_info() {
  $blocks['participate'] = array(
    'info' => t('Formulario de Concurso'), 
  );
  return $blocks;
}

/**
 * Implements hook_block_view.
 */
function socialappsm_block_view($delta = '') {
  $block = array();
  if ( !(arg(0) == 'taxonomy' && arg(1) == 'term' && intval(arg(2)) > 0 && ($term = taxonomy_term_load(arg(2))) && $term->vid == 2) ) {
    return false;
  }
  
  switch($delta) {
    case 'participate':
      if ( user_access('Participate') ) {
        $block['content'] = socialappsm_block_participate($term);
      }
      break;
  }
  return $block;
}

/**
 * Returns a chatbox that has a Raw Conversation ready to be approved.
 */
function socialappsm_block_participate($term) {
  $output = '';

  // See if logged in.
  global $user;
  if ( $user->uid == 0 ) {
    // Log In
    $login_form = fboauth_block_view(1);
    $output = $login_form['content'];
  } else {
    // Post a Picture Form
    module_load_include('inc', 'node', 'node.pages');
    $form = drupal_get_form('ticket_node_form', $node_form);
    $output = drupal_render($form);
  }
  
  return $output;
}