file(GLOB_RECURSE HDR_FILES *.hpp)
file(GLOB_RECURSE SRC_FILES *.cpp)

add_library(CU ${HDR_FILES} ${SRC_FILES} types.cpp types.hpp)

target_compile_options(CU PRIVATE -Wall -Wextra -pedantic -Wno-unused-parameter)

target_link_libraries(CU asn-ngap)
target_link_libraries(CU asn-rrc)
target_link_libraries(CU common-lib)

