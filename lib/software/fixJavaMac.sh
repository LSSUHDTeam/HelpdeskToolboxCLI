#!/bin/bash

#############
# Variables #
#############

debug=false
deploymentFile="deployment.properties"
deploymentFileLocation="~/Library/Application Support/Oracle/Java/Deployment/"
exceptionFile="exception.sites"
exceptionFileLocation="$(echo $deploymentFileLocation)security/"
user=$(whoami)
group="staff"

##############
# Debug Zone #
##############

if [ "$debug" = true ]; then
	echo "
deployment File:  $deploymentFile
Deploy Locaiton:  $deploymentFileLocation
Sites File: 	  $exceptionFile
Sites Location:   $exceptionFileLocation
             "

else

####################
# Copy Config File #
####################

sudo cp $deploymentFile $deploymentFileLocation
sudo cp $exceptionFile $exceptionFileLocation

#####################
# Restore Ownership #
#####################

sudo chown $user $group $deploymentFileLocation$deploymentFile
sudo chown $user $group $exceptionFileLocation$exceptionFile

###################
# Disable Updates #
###################

sudo defaults write /Library/Preferences/com.oracle.java.Java-Updater JavaAutoUpdateEnabled -bool false

fi
