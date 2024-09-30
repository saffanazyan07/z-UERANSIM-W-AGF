file(GLOB_RECURSE HDR_FILES *.hpp)
file(GLOB_RECURSE SRC_FILES *.cpp)

add_library(w-agf ${HDR_FILES} ${SRC_FILES})

target_compile_options(w-agf PRIVATE -Wall -Wextra -pedantic -Wno-unused-parameter)

target_link_libraries(w-agf asn-ngap)
target_link_libraries(w-agf asn-f1ap)
target_link_libraries(w-agf asn-rrc)
target_link_libraries(w-agf common-lib)

