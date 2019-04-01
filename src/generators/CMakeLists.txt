project(generators)

add_executable(${PROJECT_NAME} player.cpp)

target_link_libraries(${PROJECT_NAME}
    sub::generators
)
