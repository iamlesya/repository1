cmake_minimum_required(VERSION 3.23)
project(untitled7 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled7 main.c)

add_subdirectory(libs)
target_link_libraries(untitled7 data_structures)
