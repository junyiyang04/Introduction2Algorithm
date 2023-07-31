#!/bin/bash


cd build

rm -rf CMakeFiles
rm -rf CMakeCache.txt
rm -rf cmake_install.cmake
rm -rf I2A*
rm -rf Makefile

cmake .. && make -j12 && ./I2A
