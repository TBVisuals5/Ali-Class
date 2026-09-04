#!/bin/bash

read -p "Enter a file path: " FILE

if [ -e "$FILE" ]; then
  echo "File exists: $FILE"
  ls -l "$FILE"
else
  echo "File does not exist: $FILE"
fi
