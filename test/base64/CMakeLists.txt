# /test/base64/CMakeLists.txt

add_executable(t_base64 t_base64.cpp)
target_link_libraries(t_base64 PRIVATE base64)
