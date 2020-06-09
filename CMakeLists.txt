cmake_minimum_required(VERSION 3.10.2)

project(2048)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(2048 src/main.cpp)
add_executable(Testing test/2048Tests.cpp)

target_link_libraries(2048 ${OpenCV_LIBS})
target_link_libraries(Testing ${OpenCV_LIBS})
target_link_libraries(Testing ${GTEST_LIBRARIES} pthread)