#!/bin/bash
#
# This command expects to be run within the sites/all directory. 
# or sites/mysite.com directory. 
#
# To use this command you must have `drush make` and `git` installed.
#
# Based on script by Jeff Miccolis for Open Atrium.

if [ -f appserver.make ]; then
  echo -e "\nThis command can be used to run appserver.make in place "
#  echo -e ", or to generate"
#  echo -e "a complete distribution of Civic.\n\nWhich would you like?"
  echo "  [1] Press 1 to rebuild App Server in place (overwrites any changes!)."
  echo -e "Selection: \c"
  read SELECTION

  if [ $SELECTION = "1" ]; then

    # Run appserver.make only.
    echo "Building App Server..."
    rm -Rf modules/ themes/ libraries/
    drush -y make --working-copy --no-core --contrib-destination=. appserver.make

  elif [ $SELECTION = "2" ]; then

    # Generate a complete tar.gz of Pressflow Drupal + Civic.
    echo "Building Civic distribution..."

MAKE=$(cat <<EOF
core = "6.x"\n
api = 2\n
projects[pressflow][type] = "core"
projects[pressflow][download][url] = "http://launchpad.net/pressflow/6.x/6.19.92/+download/pressflow-6.19.92.tar.gz"
projects[pressflow][download][type] = "get"
projects[appserver][type] = "profile"\n
projects[appserver][download][type] = "git"\n
projects[appserver][download][url] = "git://github.com/starswithstripes/appserver.git"\n
EOF
)

     TAG=`cvs status appserver.make | grep "Sticky Tag:" | awk '{print $3}'`
    if [ -n $TAG ]; then
      if [ $TAG = "(none)" ]; then
        TAG="HEAD"
        VERSION="head"
      elif [ $TAG = "HEAD" ]; then
        VERSION="head"
      else
        # Convert 1-1-BETA6 into 1.1-BETA6
        VERSION=`echo ${TAG:10} | sed s/"\([0-9]\)-\([0-9]\)"/"\1.\2"/`
      fi
      MAKE="$MAKE $TAG\n"
      NAME=`echo "managingnews-$VERSION" | tr '[:upper:]' '[:lower:]'`
      echo -e $MAKE | drush make --yes - $NAME
      zip -r $NAME.zip $NAME
    else
      echo 'Could not determine CVS tag. Is o.make a CVS checkout?'
    fi
  else
   echo "Invalid selection."
  fi
else
  echo 'Could not locate file "o.make"'
fi
