#!/bin/bash

#If additional argument wasn't given, run the default test file.
if [ "$#" -eq "0" ]
then
    ./main "test.txt"
else
    ./main "$1"
fi
