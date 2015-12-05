#!/bin/bash

#############
# Variables #
#############

debug=false
javaDMGUrl="http://10.1.0.83/hdtb/software/javamac.dmg"
tempJavaFile="$(echo $TMPDIR)jre-8u45-macosx-x64.dmg"
javaVolumeLocation="/Volumes/Java\ 8\ Update\ 45"
javaPKGLocation="$javaVolumeLocation/Java\ 8\ Update\ 45.pkg"
targetLocation="/"

##############
# Debug Zone #
##############

if [ "$debug" = true ]; then
	echo "
DMG Download URL: $javaDMGUrl
Temporary File:	  $tempJavaFile
Volume Location:  $javaVolumeLocation
PKG Location: 	  $javaPKGLocation
Target Location:  $targetLocation
	     "
else

#########################################
# Download and install Java 8 Update 45 #
#########################################

curl -o $tempJavaFile $javaDMGUrl
sudo htiutil attach $tempJavaFile 
sudo installer -package $javaPKGLocation -target $targetLocation

###################################
# Fix Java (Banner/Argos/Updates) #
###################################

./fixJavaMac.sh

###########
# Cleanup #
###########

sudo hdiutil detach $javaVolumeLocation
sudo rm -f $tempJavaFile

fi
