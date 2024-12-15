cmake_minimum_required(VERSION 3.18)
project(LibTestSuite)

set(CMAKE_C_FLAGS_DEBUG "-pthread -g3 -ggdb -Wall")
set(CMAKE_C_FLAGS "")

add_library(libtestsuite testsuite.c)
