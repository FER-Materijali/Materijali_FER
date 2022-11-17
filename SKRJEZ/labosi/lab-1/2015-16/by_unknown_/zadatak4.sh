#!/bin/bash

source=$1
destination=$2
if [ ! $# -eq 2 ];then
 echo -e  "USAGE:\n\t ./zadatak4.sh source_dir destination_dir"
 exit 1
fi

if [ ! -d $source  ];then
 echo "Source has to be a directory."
 exit 1
fi
if [ ! -e $destination ];then
 #echo "Creating $destination"
 mkdir $destination
fi

counter_files=0
counter_dirs=0

for file in $(ls $source);do 
 date=$(stat "$source/$file" -c %y | cut -d "-" -f 1,2 )
 location="$destination/$date/"
 if [ ! -e $location ];then
  #echo "Creating $location"
  counter_dirs=$((counter_dirs+1))
  mkdir $location
 fi
 counter_files=$((counter_files+1))
 mv "$source/$file" "$location/$file"
done
echo -e "Files moved: $counter_files \nDirectories created: $counter_dirs"
