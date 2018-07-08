cmake_minimum_required(VERSION 2.8)

project(leetcode)

set (LEETCODE_VERSION_MAJOR 0)
set (LEETCODE_VERSION_MINOR 8)
set (LEETCODE_VERSION_PATCH 0)

# pass config to source code
configure_file (
    "${PROJECT_SOURCE_DIR}/LeetcodeConfig.h.in"
    "${PROJECT_BINARY_DIR}/LeetcodeConfig.h"
)

enable_testing()

add_subdirectory(Solution)
add_subdirectory(test)
