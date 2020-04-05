cmake_minimum_required(VERSION 3.15)
project(Client)

set(CMAKE_CXX_STANDARD 14)
set(INCLUT_DIR ${PROJECT_SOURCE_DIR}/../lib/lib)
set(LINK_DIR ${PROJECT_SOURCE_DIR}/../lib)
include_directories(${INCLUT_DIR})
link_directories(${LINK_DIR})
link_libraries(libunp.a)
aux_source_directory(../common DIR_SRCS)
add_executable(Client main.cpp ${DIR_SRCS})

target_link_libraries (Client libunp.a)