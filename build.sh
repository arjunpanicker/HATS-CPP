#! /bin/sh

# Author: Arjun Panicker
# Script follows here:

# move to build directory
cd build

# remove all the files if '-c' parameter is passed
if [ $0 == "-c" -o $0 == "--clean"] then
    rm -r *
fi

# generte make files
cmake ..

# build using native toolchain
cmake --build .
