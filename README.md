
# Installation

This is the Drupal 5 port of drupal-xhprof.  It is untested in Drupal 6 and 7.  See the upstream source from which this was forked to get the Drupal 6 version.  Or send me a message.  Or offer to help.

### 1. Install xhprof PHP extension
Follow the directions [here](http://mirror.facebook.net/facebook/xhprof/doc.html#installation "xhprof PHP extension") to install the xhprof PHP extension.  You will need to either install the extension using pecl, or alternatively, compile it yourself.

### 2. Install xhprof Drupal extension
Download drupal-xhprof and enable it in the drupal administration panel.  Settings are hard-coded in xhprof_early_enable.inc.  xhprof will profile URLs that contain the query string XHPROF_ENABLED and store the results to the filesystem and the database so you can view their details.

