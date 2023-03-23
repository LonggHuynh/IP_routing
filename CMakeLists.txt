cmake_minimum_required(VERSION 3.12)
project(LongestPrefixMatching)

set(CMAKE_CXX_STANDARD 14)


file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
