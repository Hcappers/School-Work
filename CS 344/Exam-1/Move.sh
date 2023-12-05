#!/bin/bash
#Haskell Cappers 16/2/23
#clear

choice=""
file="$1"
directory="$2"
if [ "$file" = "" ] && [ "$directory" = "" ]; then
    echo "Please enter the file and directory as command line arguments: "
    exit
fi
if [ -f "$file" ]; then
    echo "you have enter the file name" $file
else 
    echo "That is not a valid file"
    exit
fi
if [ -d "$directory" ]; then
        echo "you have enter the directory name" $directory
    else   
        echo "That is not a valid directory"
        echo "Must be the full path"
        exit
fi

bash -c "mv $file $directory"
bash -c "ls -1 $directory"