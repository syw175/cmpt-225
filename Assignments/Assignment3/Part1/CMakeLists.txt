cmake_minimum_required(VERSION 3.8)

set(This Tests)

project(${This} C CXX)

set(CMAKE_CXX C_STANDARD 11)
set(CMAKE POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

# Header files that we expect to have
set (Headers
  BST.h
  BSTNode.h
  ElementAlreadyExistsException.h
  ElementDoesNotExistException.h
  EmptyDataCollectionException.h 
  wordPair.h
)

# Source files that we expect to have
set(Sources
  BST.cpp
  BSTNode.cpp
  ElementAlreadyExistsException.cpp
  ElementDoesNotExistException.cpp
  EmptyDataCollectionException.cpp
  wordPair.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)