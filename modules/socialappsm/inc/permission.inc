<?php
/**
 * Implements hook_permission.
 */
function socialappsm_permission() {
  return array(
    'Participate' => array(
      'title' => 'Participate', 
      'description' => 'Participate', 
    ), 
  );
}