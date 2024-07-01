#!/bin/sh

cmake \
  -G "Unix Makefiles" \
  -DUNIT_TEST=ON \
  -S . \
  -B build

cd build ; make