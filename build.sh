#!/bin/bash

# Author: Arjun Panicker
# Script follows here:

# move to build directory
cd build

# remove all the files if '-c' parameter is passed
if [ "$1" = "-c" -o "$1" = "--clean" -o "$2" = "-c" -o "$2" = "--clean" ]
then
    rm -r *
else
    # Show some information regarding different build process
    echo "Use '-c' or '--clean' to make a clean build"
    echo ""
fi

# generate make files
if [ "$1" = "--shared" -o "$2" = "--shared" ]
then
    cmake .. -DGEN_SHARED_LIB=true
else
    cmake ..
fi

# build using native toolchain
cmake --build .
