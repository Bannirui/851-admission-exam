#!/bin/sh

# configure
cmake \
  -G "Unix Makefiles" \
  -DUNIT_TEST=ON \
  -S . \
  -B build

# build
cd build ; make

# run
cd build/tests ; ctest -VV