cmake_minimum_required(VERSION 3.14)

set(This bstTests)

set(Sources
  bstTests.cpp
  )

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
  # This?
  gtest_main
  BST
  BSTNode
  ElementAlreadyExistsException
  ElementDoesNotExistException
  EmptyDataCollection
  wordPair
  )

add_test(
  NAME ${This}
  COMMAND ${This}
  )
