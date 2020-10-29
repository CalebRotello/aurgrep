set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 20)

cmake_minimum_required(VERSION 3.17)
project(aurgrep)

#set(CMAKE_C_FLAGS "-march=x86-64 -02 -pipe")
#set(CMAKE_CXX_FLAGS "-march=x86-64 -pipe")
#set(LDFLAGS "-01 -Wl,-t ")

set(INCLUDE src)
set(SOURCE src)

add_executable( 
    aurgrep

    ${SOURCE}/utilities.cc
    ${SOURCE}/greper.cc

    ${SOURCE}/aurgrep.cc
)

target_link_libraries( aurgrep curlpp curl)

target_include_directories(aurgrep PUBLIC ${SRC} ${INCLUDE})

target_compile_options(aurgrep PUBLIC  -lpthread -Iinclude -lcurlpp  -lcurl -Wall)
