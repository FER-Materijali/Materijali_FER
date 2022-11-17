#!/bin/bash

source=$1
pattern="$2"
if [ ! $# -eq 2 ];then
 echo -e "Usage:\n\t ./zadatak5.sh source-dir \"pattern\""
 exit 1
fi
if [ ! -d $source ];then
 echo "Source must me directory"
 exit 1
fi

echo "Arguments: $@"
words=$(find $source -name "$pattern" -print0 | wc -w --files0-from=- | tail -n -1 | cut -d " " -f 1)
echo "Number of words: $words"

