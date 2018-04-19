set(libSol_SRCS
    solution.h
    solution.cpp
)

# Declare the library
add_library(libSol STATIC
    ${libSol_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(libSol PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
