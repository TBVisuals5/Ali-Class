#!/bin/bash

DIR="$1"

if [ -z "$DIR" ]; then
  echo "Usage: ./file-count.sh <directory>"
  exit 1
fi

if [ ! -d "$DIR" ]; then
  echo "Directory not found: $DIR"
  exit 1
fi

LOG="file-count.log"

echo "File type counts for directory: $DIR" >> "$LOG"
echo "Timestamp: $(date)" >> "$LOG"

find "$DIR" -type f | while read -r FILE; do
  EXT="${FILE##*.}"
  if [ "$EXT" = "$FILE" ]; then
    EXT="no_extension"
  fi
  echo "$EXT" >> /tmp/file-types.tmp
done

sort /tmp/file-types.tmp | uniq -c >> "$LOG"
rm /tmp/file-types.tmp

echo "Results logged to $LOG"
