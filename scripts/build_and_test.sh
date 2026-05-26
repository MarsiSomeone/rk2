#!/bin/bash
set -e

rm -rf build
mkdir build
cd build
cmake .. -DBUILD_TESTS=ON
cmake --build .
ctest --output-on-failure
cmake --build . --target package
mkdir -p ../Release
cp Release/*.deb ../Release/ 
