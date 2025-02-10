# /src/base64/CMakeLists.txt

add_library(denko STATIC
  base64/base64.cpp
)

target_include_directories(denko PUBLIC
  base64
)
