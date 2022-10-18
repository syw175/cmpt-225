cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Tell Cmake that we are going to have unit tests
enable_testing()

# Header files that we expect to have
set (Headers
  Example.hpp
)

# Source files that we expect to have
set(Sources
  Example.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

# Keep our tests separate from our code
add_subdirectory(test)
