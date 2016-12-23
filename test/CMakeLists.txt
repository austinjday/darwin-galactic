project(test)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googlemock/include)
include_directories(lib/googletest-master/googletest/include)

file(GLOB_RECURSE TEST_SOURCE_FILES tests/*.cpp)
message(STATUS ${TEST_SOURCE_FILES})
add_executable(runUnitTests main.cpp ${TEST_SOURCE_FILES})

target_link_libraries(runUnitTests gtest gtest_main)
target_link_libraries(runUnitTests core)