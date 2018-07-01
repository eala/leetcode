file(GLOB libSol_HDRS inlcude/*.h)
file(GLOB libSol_SRCS src/*.cpp)

# Declare the library
add_library(libSol STATIC
    ${libSol_SRCS} ${libSol_HDRS}
)

# Specify here the include directories exported
# by this library
target_include_directories(libSol PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
