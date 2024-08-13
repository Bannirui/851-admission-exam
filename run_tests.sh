#!/bin/sh

# clean
cd build ; make clean

# build
cd build ; make

# run
cd build/tests ; ctest -VV