<?php

// $Id$

/**
 * @file
 */

/**
 * XHProf calls this both 'source' and 'run_type'.
 * It's basically a way to namespace XHProf runs.
 */
define('XHPROF_SOURCE', 'drupal_xhprof');

/**
 * Set to true when XHProf profiling has started.
 */
$xhprof_profiling_started = false;

function xhprof_early_enable() {
  if (!extension_loaded('xhprof') or !function_exists("xhprof_enable")) {
    return;
  }
  
  // So we don't waste time checking again on xhprof_exit()  
  global $xhprof_profiling_started;

  if (xhprof_profiling_enabled()) {
    /* hard-code the flags so we don't have to talk to the database.
     * flags are:
     *  XHPROF_FLAGS_CPU (expensive, don't use in production)
     *  XHPROF_FLAGS_MEMORY
     *  XHPROF_FLAGS_BO_BUILTINS
     */ 
    xhprof_enable( XHPROF_FLAGS_MEMORY + XHPROF_FLAGS_NO_BUILTINS );
    $xhprof_profiling_started = true;
  }
}

/**
 * Determines whether or not to profile the current request.
 */
function xhprof_profiling_enabled() {
  $enabled = strpos($_SERVER['REQUEST_URI'], 'XHPROF_ENABLED');

  if ($enabled === false) {
    return false;
  }
  else { return true; }
}
