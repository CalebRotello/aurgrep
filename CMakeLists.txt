set(CMAKE_CXX_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_STANDARD 20)

cmake_minimum_required(VERSION 3.17)
project(aurgrep)


set(INCLUDE src)
set(SOURCE src)

set( CURL_LIBRARY ${CMAKE_SOURCE_DIR}/lib )
set( CURL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include )
find_package( CURL )

include_directories( ${CURL_INCLUDE_DIRS} )
link_directories( ${CURL_LIBRARIES} )

add_executable( 
    aurgrep

    ${SOURCE}/utilities.cc
    ${SOURCE}/greper.cc

    ${SOURCE}/aurgrep.cc
)


target_include_directories(aurgrep PUBLIC ${SRC} ${INCLUDE} )

target_compile_options(aurgrep PUBLIC -Wall )

target_link_libraries(aurgrep curl)