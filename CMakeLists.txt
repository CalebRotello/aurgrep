set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_STANDARD 20)

cmake_minimum_required(VERSION 3.17)
project(aurgrep)


set(INCLUDE src)
set(SOURCE src)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable( 
    aurgrep

    ${SOURCE}/utilities.cc
    ${SOURCE}/greper.cc

    ${SOURCE}/aurgrep.cc
)

target_include_directories(aurgrep PUBLIC ${SRC} ${INCLUDE})

target_compile_options(aurgrep PUBLIC -Wall)