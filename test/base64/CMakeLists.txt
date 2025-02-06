# /test/base64/CMakeLists.txt

add_executable(t_base64 t_base64.cpp)
target_link_libraries(t_base64 PRIVATE denko-base64)

add_executable(t_encoder t_encoder.cpp)
target_link_libraries(t_encoder PRIVATE denko-base64)
