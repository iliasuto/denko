# /test/base64/CMakeLists.txt

add_executable(example_base64_test example_base64_test.cpp)
target_link_libraries(example_base64_test PRIVATE denko-base64)

add_executable(example_base64_encoder example_base64_encoder.cpp)
target_link_libraries(example_base64_encoder PRIVATE denko-base64)

add_executable(example_base64_decoder example_base64_decoder.cpp)
target_link_libraries(example_base64_decoder PRIVATE denko-base64)
