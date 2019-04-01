cmake_minimum_required(VERSION 3.5.0)
project(constructs)

include_directories(include)

add_library(${PROJECT_NAME} Entity.cpp EntityAlignment.cpp Sentient.cpp races/Human.cpp)

add_library(sub::constructs ALIAS ${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)