file(GLOB Sol_HDRS inlcude/*.h)
file(GLOB Sol_SRCS src/*.cpp)

set(CMAKE_MACOSX_RPATH 1)

# Declare the library
#add_library(Sol STATIC
add_library(Sol SHARED
    ${Sol_SRCS} ${Sol_HDRS}
)

#include_directories(${PROJECT_BINARY_DIR})
#target_link_libraries(Sol
#    testSolution
#)

set(LEETCODE_VERSION_STRING ${LEETCODE_VERSION_MAJOR}.${LEETCODE_VERSION_MINOR}.${LEETCODE_VERSION_PATCH})

set_target_properties(Sol PROPERTIES
    VERSION ${LEETCODE_VERSION_STRING}
    SOVERSION ${LEETCODE_VERSION_MAJOR}
)

target_include_directories(Sol PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
