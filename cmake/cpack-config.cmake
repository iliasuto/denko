# pack config
set(CPACK_PACKAGE_NAME denko)
set(CPACK_PACKAGE_VERSION ${CMAKE_PROJECT_VERSION})
set(CPACK_PACKAGE_DIRECTORY ${CMAKE_BINARY_DIR}/release)

# generated pack format
set(CPACK_BINARY_7Z "ON")
set(CPACK_BINARY_STGZ "OFF")
set(CPACK_BINARY_TBZ2 "OFF")
set(CPACK_BINARY_TGZ "ON")
set(CPACK_BINARY_TXZ "ON")
set(CPACK_BINARY_TZ "OFF")
set(CPACK_BINARY_TZST "OFF")
set(CPACK_BINARY_ZIP "ON")

include(CPack)

# ==================
# Debug Informations
# ==================
message("===== CPack Config =====")
message("pack_name: " ${CPACK_PACKAGE_NAME})
message("pack_version: " ${CPACK_PACKAGE_VERSION})
message("pack_directory: " ${CPACK_PACKAGE_DIRECTORY})
message("========================")
