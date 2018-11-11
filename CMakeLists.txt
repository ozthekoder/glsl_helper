cmake_minimum_required(VERSION 3.5)
project(glsl_helper VERSION 1.0.0 LANGUAGES C CXX)
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

file(GLOB GLSL_HELPER_SOURCES src/*.cpp)
add_library(glsl ${GLSL_HELPER_SOURCES})
target_include_directories(glsl PRIVATE ${INCLUDE_DIR})
include_directories(${INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(${PROJECT_NAME} glsl)
