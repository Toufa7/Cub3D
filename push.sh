#!/bin/bash

git add .
echo "Insert your commit >"
read -r commit
git commit -m commit
echo "Pull or Push >"
read -r answer
if [[ $answer == "pull" ]];
then
    git pull
    echo "Done with pulling, do you wanna push your files (y/n)?"
    read -r pushing
    if [[ $pushing == "y" ]];
    then
        git push
    else
        exit;
    fi
elif [[ $answer == "push" ]];
then
    git pull
fi
