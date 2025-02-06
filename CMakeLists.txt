# /CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

project(DenKo
  VERSION 0.0.1
  DESCRIPTION "The DenKo means Decoding and Encoding. "
  LANGUAGES C CXX
)


add_subdirectory(src bin)
add_subdirectory(test bin/test)


include(cmake/install-config.cmake)
include(cmake/cpack-config.cmake)
include(cmake/path-check.cmake)
