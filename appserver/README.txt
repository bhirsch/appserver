App Server
=====================

About App Server
-----------------
This module does two things: 

1. It provides a content type called "App" to help users easily create apps.
   An app is really just a recipie for a feature, including all the feature's
   components (Drupal modules, third party libraries, etc.). 
   
   Note: The term "feature" here is generic, not specificially in reference to
   the Features module or features modules created by the Features module. 
   But features modules can certainly be included in apps.

2. It uses information stored in app nodes to build a related .make file and 
   then assemble the app.


Configuration
---------------
1. Go to Home >> Administration >> Configuration >> Media >> App Server
   (that is, the path admin/config/media/appserver). 

2. Designate which of the system's files directories you will use for storing 
   apps (public or private).

3. Enter a path to Drush Make. E.g. /path/to/drush_make or /home/username/.drush/drush_make.


File storage
--------------
App Server's configuration page lets you determine whether your files will be 
stored in a public or private directory. Then app files get stored like this: 

scheme://appserver/appname
scheme://appserver/appname/appname.make
scheme://appserver/appname/appname.tar.gz

For example, apps in a public files directory probably get stored here: 
sites/default/files/appserver

Apps in a private files directory probably get stored somewhere like this:
../private_files/appserver


Drush usage
-------------
- `drush appserver-make-make [app nid]`

    Output contents of a make file for the requested app. 

- `appserver-make-app [app nid]`

    Build a tarball of the requested app. 
    
    Note: If your webserver runs appserver_make_app(), it will create the 
    directory where your .make files and apps are stored. Then you will likely
    get errors when you run `drush ama [nid]` because of permission issues. To 
    work around this, either change the permissions/ownership on your appserver 
    directory or run `drush ama` as superuser or www-data. 
