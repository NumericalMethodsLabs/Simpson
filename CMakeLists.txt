cmake_minimum_required(VERSION 3.17)
project(Simpson)

set(CMAKE_CXX_STANDARD 14)

add_definitions(-DERROR_PRINT)

add_library(${PROJECT_NAME} Simpson.cpp Simpson.h)