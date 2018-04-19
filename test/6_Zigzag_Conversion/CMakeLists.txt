file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testSolution ${SRCS})

TARGET_LINK_LIBRARIES(testSolution
    libSol
    libgtest
    libgmock
)

add_test(NAME testSolution
    COMMAND testSolution)
