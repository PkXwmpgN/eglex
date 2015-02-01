# Examples eglex desktop entry point
cmake_minimum_required(VERSION 2.8.12)

project(EGLEX)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(core)
add_subdirectory(examples/eglex/initialize)
add_subdirectory(examples/eglex/configurate)
add_subdirectory(examples/eglex/configurate_custom)
add_subdirectory(examples/eglex/configs)
add_subdirectory(examples/eglex/context)
add_subdirectory(examples/eglex/surface)