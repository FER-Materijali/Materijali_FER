#!/bin/bash

for file in $(ls);do
 if [[ $file =~ localhost_access_log\.([0-9]{4})-02-([0-9]{2})\.txt ]];then
  date="datum: ${BASH_REMATCH[2]}-02-${BASH_REMATCH[1]}"
  echo "$date :"
  echo "-------------------------------------------------------------"
  cut $file -d "\"" -f 2 | sort | uniq -c | sort -nr | tr -s " "  | sed 's/ / : /2'
 fi
done
