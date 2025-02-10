# include
set(DENKO_SRC ${CMAKE_SOURCE_DIR}/src)
set(DENKO_INCLUDE
  ${DENKO_SRC}/base64/base64.h
)

# lib
set(DENKO_LIB denko)

# install config
install(TARGETS ${DENKO_LIB} DESTINATION lib)
install(FILES ${DENKO_INCLUDE} DESTINATION include/denko/)

# ==================
# Debug Informations
# ==================
message("===== Install Item Check =====")

message("> LIBS: ")
foreach(item ${DENKO_LIB})
  message(${item})
endforeach()

message("> INCLUDES: ")
foreach(item ${DENKO_INCLUDE})
  message(${item})
endforeach()

message("==============================")
