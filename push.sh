#!/bin/bash

# Cillian Young

folder=".git"
Log="log.txt"
alter_folder="build"
#if [ -d $alter_folder ]; then
 #   cd ..
#if

if [ $# -ge 1 ]; then
    if [ -d $folder ]; then 
        echo "> find repository"
        time3=$(date "+%Y-%m-%d %H:%M:%S")
        echo "> ($time3)pushing to origin master ..."
        if [ ! -f $Log ]; then
            touch $Log
            chmod +x $Log
            echo "> Success create $Log"
            echo -e "---log create---" >> $Log
        fi
        echo -e "$time3 -> log: $*" >> $Log
        git add . && git commit  -m "$*" && git push origin master
    else
        echo "> Error: push from the folder containing '.git'"
    fi
else
    echo "> Error: short of parameter"
    echo "  Usage: ./push.sh <Description>"
    echo "  \"Description\" could be the brief of this push or any thing you want"
    if [ ! -d $folder ]; then 
        echo "> Error: push from the folder containing '.git'"
    fi
fi
