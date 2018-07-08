file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testSolution ${SRCS})

TARGET_LINK_LIBRARIES(testSolution
    Sol
    libgtest
    libgmock
)

include_directories(${PROJECT_BINARY_DIR})

add_test(NAME testSolution
    COMMAND testSolution)
