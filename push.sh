#!/bin/bash

git add .
echo "Insert your commit >"
read -r commit
git commit -m commit

echo "Pull or Push >"
read -r answer
if [ [ answer == "pull"] ];
then
    git pull
elif [ [ answer == "push"]];
then
    git pull
fi