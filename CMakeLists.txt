cmake_minimum_required(VERSION 3.5.0)
project(legion)

include_directories(include)

add_subdirectory(src/constructs)
add_subdirectory(src/utilities)
#add_subdirectory(src/generators)
#add_subdirectory(src/managers)
#add_subdirectory(src/player_types)
add_subdirectory(src/launcher)