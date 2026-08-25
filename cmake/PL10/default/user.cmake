# user.cmake — safe to commit; not overwritten by MCC
# Add application-layer source files to the build

list(APPEND PL10_default_default_XC32_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../config.mcc/src/app.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../config.mcc/src/gpio.c"
)

# Add include directory for application headers
target_include_directories(PL10_default_default_XC32_compile PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../config.mcc/src"
)
