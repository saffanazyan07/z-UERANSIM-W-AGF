file(GLOB_RECURSE HDR_FILES *.hpp)
file(GLOB_RECURSE SRC_FILES *.cpp)

add_library(DU ${HDR_FILES} ${SRC_FILES})

target_compile_options(DU PRIVATE -Wall -Wextra -pedantic -Wno-unused-parameter)

target_link_libraries(DU asn-ngap)
target_link_libraries(DU asn-rrc)
target_link_libraries(DU common-lib)

