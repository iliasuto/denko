# /CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

project(DenKo
  VERSION 0.0.1
  LANGUAGES CXX
  DESCRIPTION "The DenKo means Decoding and Encoding. "
)

add_subdirectory(src bin)
add_subdirectory(test test)
