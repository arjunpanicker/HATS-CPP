#!/bin/bash

# Author: Arjun Panicker
# Script follows here:

# move to build directory
cd build

if [ "$1" = "-rs" -o "$2" = "-rs" -o "$3" = "-rs" ]
then
    rm -r preprocessed_data.csv model.h embeddings.vec
fi

# remove all the files if '-c' parameter is passed
if [ "$1" = "-c" -o "$2" = "-c" -o "$3" = "-c" ]
then
    rm -r *
else
    # Show some information regarding different build process
    echo "Use '-c' or '--clean' to make a clean build"
    echo ""
fi

# generate make files
if [ "$1" = "--shared" -o "$2" = "--shared" -o "$3" = "--shared" ]
then
    cmake .. -DGEN_SHARED_LIB=true
else
    cmake ..
fi

# build using native toolchain
cmake --build .
