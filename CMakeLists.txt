cmake_minimum_required(VERSION 3.14)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake.build_settings")

project(burkov_d_v)

include(cmake.build_settings/build_prefix.cmake)

include_directories(labs)
add_subdirectory(labs)
