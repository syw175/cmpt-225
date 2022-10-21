cmake_minimum_required(VERSION 3.8)

set(This BST-TESTING)

set(Sources
    bstTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Tests
)

add_test(
    NAME ${This}
    COMMAND ${This}
)