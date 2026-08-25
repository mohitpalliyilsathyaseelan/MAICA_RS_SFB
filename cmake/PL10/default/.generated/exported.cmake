set(DEPENDENT_MP_BIN2HEXPL10_default_v07FH2i6 "c:/Program Files/Microchip/xc32/v5.10/bin/xc32-bin2hex.exe")
set(DEPENDENT_DEPENDENT_TARGET_ELFPL10_default_v07FH2i6 ${CMAKE_CURRENT_LIST_DIR}/../../../../out/PL10/default.elf)
set(DEPENDENT_TARGET_DIRPL10_default_v07FH2i6 ${CMAKE_CURRENT_LIST_DIR}/../../../../out/PL10)
set(DEPENDENT_BYPRODUCTSPL10_default_v07FH2i6 ${DEPENDENT_TARGET_DIRPL10_default_v07FH2i6}/${sourceFileNamePL10_default_v07FH2i6}.c)
add_custom_command(
    OUTPUT ${DEPENDENT_TARGET_DIRPL10_default_v07FH2i6}/${sourceFileNamePL10_default_v07FH2i6}.c
    COMMAND ${DEPENDENT_MP_BIN2HEXPL10_default_v07FH2i6} --image ${DEPENDENT_DEPENDENT_TARGET_ELFPL10_default_v07FH2i6} --image-generated-c ${sourceFileNamePL10_default_v07FH2i6}.c --image-generated-h ${sourceFileNamePL10_default_v07FH2i6}.h --image-copy-mode ${modePL10_default_v07FH2i6} --image-offset ${addressPL10_default_v07FH2i6} 
    WORKING_DIRECTORY ${DEPENDENT_TARGET_DIRPL10_default_v07FH2i6}
    DEPENDS ${DEPENDENT_DEPENDENT_TARGET_ELFPL10_default_v07FH2i6})
add_custom_target(
    dependent_produced_source_artifactPL10_default_v07FH2i6 
    DEPENDS ${DEPENDENT_TARGET_DIRPL10_default_v07FH2i6}/${sourceFileNamePL10_default_v07FH2i6}.c
    )
