#!/bin/sh

set -e

cur_dir=$(cd $(dirname $0); pwd)

# run unit test
cd ${cur_dir}/build/tests ; ctest -VV -R "^test111$"
