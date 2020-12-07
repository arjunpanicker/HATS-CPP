#!/bin/bash

# Author: Arjun Panicker
# Script follows here:

# move to build directory
cd build

# remove all the files if '-c' parameter is passed
if [ "$1" = "-c" -o "$1" = "--clean" ]
then
    rm -r *
else
    # Show some information regarding different build process
    echo "Use '-c' or '--clean' to make a clean build"
    echo ""
fi

# generte make files
cmake ..

# build using native toolchain
cmake --build .
