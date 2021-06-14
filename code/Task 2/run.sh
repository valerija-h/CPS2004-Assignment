#!/bin/bash

cd src
#If additional argument wasn't given, run the default test file.
if [ "$#" -eq "0" ]
then
    java Runner "../test.txt"
else
    java Runner "$1"
fi
cd ..
