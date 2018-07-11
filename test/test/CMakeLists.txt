file(GLOB SRCS *.cpp *.h)

add_executable(testSolution ${SRCS})

target_link_libraries(testSolution
    Sol
    libgtest
    libgmock
)

target_include_directories(testSolution PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

include_directories(${PROJECT_BINARY_DIR})

add_test(NAME testSolution
    COMMAND testSolution)
