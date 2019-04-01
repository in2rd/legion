cmake_minimum_required(VERSION 3.5.0)
project(utilities)

include_directories(include)

add_library(${PROJECT_NAME} Dice.cpp)

add_library(sub::utilities ALIAS ${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)