# IPv4 unit tests
add_subdirectory(ipv4)

# All suites
add_executable(ALL_SUITES main.cpp)
target_link_libraries(ALL_SUITES gtest gtest_main)
target_link_libraries(ALL_SUITES SocketPP)

add_test(ALL ALL_SUITES)