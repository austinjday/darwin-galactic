cmake_minimum_required(VERSION 3.6)
project(DarwinGalactic)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

add_subdirectory(src)
add_subdirectory(test)