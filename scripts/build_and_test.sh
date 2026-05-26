#!/bin/bash
set -e

mkdir -p build
cd build
cmake ..
cmake --build .
ctest --output-on-failure
cmake --build . --target package
mkdir -p ../Release
cp *.deb ../Release/
