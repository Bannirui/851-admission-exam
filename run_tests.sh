#!/bin/sh

set -e

cur_dir=$(cd $(dirname $0); pwd)

# clean
cd ${cur_dir}/build ; make clean ; make

# run unit test
cd ${cur_dir}/build/tests ; ctest -VV