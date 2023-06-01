file(GLOB_RECURSE HDR_FILES *.hpp)
file(GLOB_RECURSE SRC_FILES *.cpp)

add_library(CU ${HDR_FILES} ${SRC_FILES})

target_compile_options(CU PRIVATE -Wall -Wextra -pedantic -Wno-unused-parameter)

target_link_libraries(CU asn-ngap)
target_link_libraries(CU asn-rrc)
target_link_libraries(CU asn-f1ap)
target_link_libraries(CU common-lib)
target_link_libraries(CU boost_system boost_thread)
target_link_libraries(CU sctp) # Linux SCTP
