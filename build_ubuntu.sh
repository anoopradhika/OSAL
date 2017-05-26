#/bin/bash
cmake -D CMAKE_C_COMPILER=gcc-5 -D CMAKE_CXX_COMPILER=g++-5 -D CMAKE_CXX_FLAGS=--std=c++11 .

make
