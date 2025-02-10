# /CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

project(DenKo
  VERSION 0.0.3
  DESCRIPTION "The DenKo means Decoding and Encoding. "
  LANGUAGES C CXX
)

# build options
set(DENKO_BUILD_SRC ON)
set(DENKO_BUILD_EXAMPLES ON)

# src
if(${DENKO_BUILD_SRC})
  add_subdirectory(src binary)
endif()

# examples
if(${DENKO_BUILD_EXAMPLES})
  add_subdirectory(examples examples)
endif()

# config
include(cmake/install-config.cmake)
include(cmake/cpack-config.cmake)
include(cmake/config-check.cmake)
