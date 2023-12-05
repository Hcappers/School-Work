#!bin/bash
clear
choice=""
while [ ! "$choice" = "Q" ] && [ ! "$choice" = "q" ]; do
    echo "1)List all files"
    echo "2)List all files in specific directory"
    echo "3)Display all cureent process on the system"
    echo "4)Display all the global enviroment variables"
    read -p "Make a selection please:" choice
    if [ "$choice" = "" ]; then
        echo "You did not make a selection"
        echo
        continue
    fi
    if [ "$choice" = "1" ]; then
        bash -c "ls -a"
        continue
    fi
    if [ "$choice" = "2" ]; then
        read -p "What is the path you would like to look in please include the / aswell" $dest
        bash -c "find '$dest'"
        echo
        continue
    fi
    if [ "$choice" = "3" ]; then
        base -c "ps aux"
        echo
        continue
    fi
    if [ "$choice" = "3" ]; then
        bash -c "env"
        echo
        continue
    fi
    echo "$choice is invalid"
    echo
done
