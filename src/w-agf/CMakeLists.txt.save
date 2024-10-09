file(GLOB_RECURSE HDR_FILES *.hpp)
file(GLOB_RECURSE SRC_FILES *.cpp)

add_library(w_agf ${HDR_FILES} ${SRC_FILES})

target_compile_options(w_agf PRIVATE -Wall -Wextra -pedantic -Wno-unused-parameter)

target_link_libraries(w_agf asn-ngap)
target_link_libraries(w_agf asn-f1ap)
target_link_libraries(w_agf asn-rrc)
target_link_libraries(w_agf common-lib)

