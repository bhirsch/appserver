; App Server
; -----------

; Core version
; -------------
core = 7.x

; API version
; -----------
api = 2

; Core project
; ------------
projects[] = drupal

; Contrib projects
; ----------------
projects[admin][version] = 2.0-beta3

projects[ctools][version] = 1.0-alpha4

projects[devel][version] =1.0 

projects[features][version] = 1.0-beta2

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Note: As of 5/11/11 the latest release is 7.x-1.0-rc2.              ;
;   This release doesn't export field_groups correctly with Features. ;
;   The latest dev version, 7.x-1.x does work with Features.          ;
;   (see http://drupal.org/node/1043430#comment-4351636)              ;
;   Don't checkout out from git once the next release comes out.      ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
projects[field_group][type] = module
projects[field_group][download][type] = git 
projects[field_group][download][url] = http://git.drupal.org/project/field_group.git
projects[field_group][download][branch] = 7.x-1.x

projects[references][version] = 2.x-dev

projects[views][version] = 3.0-beta3  

; Custom projects
; ---------------
projects[appserver][type] = module
projects[appserver][download][type] = git 
projects[appserver][download][url] = https://bhirsch@github.com/bhirsch/appserver.git
projects[appserver][download][branch] = 7.x-1.x
projects[appserver][directory_name] = custom 

; Libraries
; ---------
; none 
