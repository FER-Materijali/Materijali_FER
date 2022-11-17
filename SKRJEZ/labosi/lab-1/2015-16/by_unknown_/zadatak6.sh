#!/bin/bash

backup=${!#}

if [ "$#" -lt 2  ];then
 echo -e "Usage:\n\t ./zadatak6.sh source-dir backup-dir"
 exit 1
fi
if [ ! -d  "$backup" ];then
 mkdir $backup
 echo "Created directory $backup"
fi
#echo "$@"

broj_datoteka=0
for arg;do
 if [ -d "$arg" ];then
  #echo "$arg is directory. Skipping"
  continue
 fi
 if [ ! -r "$arg" -a -e "$arg" ];then
  echo "Can't read $arg or does not exist."
  continue
 fi
 cp "$arg" "$backup"
 broj_datoteka=$((broj_datoteka+1))
done
if [ $broj_datoteka -gt 0 ];then
 echo "Copied $broj_datoteka files to directory $backup"
else
 echo "Didn't copy files."
fi 
