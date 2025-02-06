set(CPACK_PACKAGE_NAME denko)
set(CPACK_PACKAGE_VERSION ${CMAKE_PROJECT_VERSION})
set(CPACK_PACKAGE_DIRECTORY ${CMAKE_SOURCE_DIR}/release)
include(CPack)

# ==================
# Debug Informations
# ==================
message("===== CPack Config =====")
message("pack_name: " ${CPACK_PACKAGE_NAME})
message("pack_version: " ${CPACK_PACKAGE_VERSION})
message("pack_directory: " ${CPACK_PACKAGE_DIRECTORY})
message("========================")
