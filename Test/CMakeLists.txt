cmake_minimum_required(VERSION 3.0)
project(Test)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")
aux_source_directory(../common DIR_SRCS)
aux_source_directory(../common/threadPool DIR_SRCS2)
add_executable(Test test.cpp ${DIR_SRCS} ${DIR_SRCS2})