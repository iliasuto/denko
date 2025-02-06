# /src/base64/CMakeLists.txt

add_library(denko-base64 STATIC base64.cpp)
target_include_directories(denko-base64 PUBLIC .)

install(
	TARGETS denko-base64
	DESTINATION lib
)

install(
	FILES ./base64.h
	DESTINATION include/denko/
)