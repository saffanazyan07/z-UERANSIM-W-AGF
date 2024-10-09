file(GLOB HDR_FILES *.h)
file(GLOB SRC_FILES *.c)

add_library(asn-f1ap ${HDR_FILES} ${SRC_FILES})
target_link_libraries(asn-f1ap asn-asn1c)
