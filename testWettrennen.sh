#!/bin/bash
var=0
while :;
do
    ./wettrennen
    RET=$?
    var=$((var+1))         
    echo $var
    if [ $RET -eq 1 ]
         then echo "it happened!"
         break;
    fi
done
