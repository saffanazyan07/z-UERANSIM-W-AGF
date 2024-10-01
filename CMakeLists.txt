############### edited by zyz 09/30/24 #################
cmake_minimum_required(VERSION 3.17)
project(ueransim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

include_directories(src)

#################### SUB DIRECTORIES ####################

add_subdirectory(src/ext)
add_subdirectory(src/utils)
add_subdirectory(src/asn/asn1c)
add_subdirectory(src/asn/rrc)
add_subdirectory(src/asn/ngap)
add_subdirectory(src/asn/f1ap)
add_subdirectory(src/lib)
add_subdirectory(src/CU)
add_subdirectory(src/w_agf)
add_subdirectory(src/fnrg)

#################### CU EXECUTABLE ####################

add_executable(nr-CU src/CU.cpp)

target_link_libraries(nr-CU pthread)

target_compile_options(nr-CU PRIVATE -Wall -Wextra -pedantic)

target_link_libraries(nr-CU asn-rrc)
target_link_libraries(nr-CU asn-ngap)
target_link_libraries(nr-CU asn-f1ap)
target_link_libraries(nr-CU common-lib)
target_link_libraries(nr-CU CU)

#################### DU EXECUTABLE ####################

add_executable(nr-w_agf src/w_agf.cpp)

target_link_libraries(nr-w_agf pthread)

target_compile_options(nr-w_agf PRIVATE -Wall -Wextra -pedantic)

target_link_libraries(nr-w_agf asn-rrc)
target_link_libraries(nr-w_agf asn-f1ap)
target_link_libraries(nr-w_agf common-lib)
target_link_libraries(nr-w_agf w_agf)

#################### FN-RG EXECUTABLE ####################

add_executable(nr-fnrg src/fnrg.cpp)
target_link_libraries(nr-fnrg pthread)
target_compile_options(nr-fnrg PRIVATE -Wall -Wextra -pedantic)

target_link_libraries(nr-fnrg common-lib)
target_link_libraries(nr-fnrg fnrg)

###################### IF BINDER ######################
add_library(devbnd SHARED src/binder.cpp)
target_compile_options(devbnd PRIVATE -D_GNU_SOURCE -Wall -Wextra)
target_link_options(devbnd PRIVATE -nostartfiles)
target_link_libraries(devbnd dl)

#################### CLI EXECUTABLE ####################
add_executable(nr-cli src/cli.cpp)
target_link_libraries(nr-cli pthread)
target_compile_options(nr-cli PRIVATE -Wall -Wextra -pedantic)

target_link_libraries(nr-cli common-lib)
