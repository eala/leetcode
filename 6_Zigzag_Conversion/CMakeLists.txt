set(Main_SRCS
    main.cpp
)

add_executable(solution
    ${Main_SRCS}
)

# Specify here the libraries this program depends on
target_link_libraries(solution
)

install(TARGETS solution DESTINATION bin)
