######################################################################
# CMakeLists.txt generated for component Code_Gen_Model
# Product type: executable
######################################################################
cmake_minimum_required(VERSION 3.12)
project(Code_Gen_Model)
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()


######################################################################
## Path variables
######################################################################
get_filename_component(START_DIR .. ABSOLUTE)
set(MATLAB_ROOT C:/Program\ Files/MATLAB/R2023a CACHE PATH "")
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
if(${CMAKE_CURRENT_BINARY_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    set(BUILDING_IN_SOURCE_DIR TRUE)
    set(BINARY_START_DIR "${START_DIR}")
else()
    set(BUILDING_IN_SOURCE_DIR FALSE)
    set(BINARY_START_DIR "${CMAKE_BINARY_DIR}")
endif()
if(WIN32 AND NOT MINGW)
    set(SYSLIB_PREFIX "lib")
else()
    set(SYSLIB_PREFIX "")
endif()

######################################################################
## System libraries
######################################################################
find_library(FOUND_LIBM m NO_SYSTEM_ENVIRONMENT_PATH PATHS ${CMAKE_C_IMPLICIT_LINK_DIRECTORIES}
    ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

######################################################################
## Target definition and commands
######################################################################
set(CODE_GEN_MODEL_COMMON_DEFINES -DMODEL=Code_Gen_Model
    -DNUMST=1
    -DNCSTATES=0
    -DHAVESTDIO
    -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
    -DCLASSIC_INTERFACE=0
    -DALLOCATIONFCN=0
    -DTID01EQ=0
    -DTERMFCN=1
    -DONESTEPFCN=1
    -DMAT_FILE=0
    -DMULTI_INSTANCE_CODE=0
    -DINTEGER_CODE=0
    -DMT=0
    -D_CRT_SECURE_NO_WARNINGS)

set(CODE_GEN_MODEL_COMMON_COMPILER_FLAGS /wd4251
    -EHs)

add_library(Code_Gen_Model_objects OBJECT ${START_DIR}/Code_Gen_Model_ert_rtw/Code_Gen_Model.c
    ${START_DIR}/Code_Gen_Model_ert_rtw/Code_Gen_Model_data.c
    ${START_DIR}/Code_Gen_Model_ert_rtw/rtGetInf.c
    ${START_DIR}/Code_Gen_Model_ert_rtw/rtGetNaN.c
    ${START_DIR}/Code_Gen_Model_ert_rtw/rt_nonfinite.c)
set_target_properties(Code_Gen_Model_objects PROPERTIES
    PREFIX ""
    POSITION_INDEPENDENT_CODE ON)
target_compile_features(Code_Gen_Model_objects PUBLIC c_std_99)
target_compile_definitions(Code_Gen_Model_objects PRIVATE ${CODE_GEN_MODEL_COMMON_DEFINES})
target_compile_options(Code_Gen_Model_objects PRIVATE ${CODE_GEN_MODEL_COMMON_COMPILER_FLAGS})
target_include_directories(Code_Gen_Model_objects PUBLIC $<BUILD_INTERFACE:${START_DIR}>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>>
    $<BUILD_INTERFACE:${START_DIR}/Code_Gen_Model_ert_rtw>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/Code_Gen_Model_ert_rtw>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/extern/include>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/simulink/include>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/src>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/src/ext_mode/common>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/ert>)
target_link_libraries(Code_Gen_Model_objects PUBLIC $<$<BOOL:${FOUND_LIBM}>:m>)

add_executable(Code_Gen_Model  ${START_DIR}/Code_Gen_Model_ert_rtw/ert_main.c)
set_target_properties(Code_Gen_Model PROPERTIES
    PREFIX ""
    POSITION_INDEPENDENT_CODE ON)
target_compile_features(Code_Gen_Model PUBLIC c_std_99)
target_compile_definitions(Code_Gen_Model PRIVATE ${CODE_GEN_MODEL_COMMON_DEFINES})
target_compile_options(Code_Gen_Model PRIVATE ${CODE_GEN_MODEL_COMMON_COMPILER_FLAGS})
target_link_libraries(Code_Gen_Model PRIVATE Code_Gen_Model_objects)
if(WIN32)
   target_link_libraries(Code_Gen_Model PRIVATE kernel32
       ws2_32
       mswsock
       advapi32)
endif()

######################################################################
## Extract debug symbols
######################################################################
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    string(APPEND _dsymutilcmd "$<IF:$<CONFIG:DEBUG,RELWITHDEBINFO>,"
                "xcrun;dsymutil;$<TARGET_FILE:Code_Gen_Model>;--flat,"
                "true"
        >)
    add_custom_command(TARGET Code_Gen_Model
            POST_BUILD
            COMMAND "${_dsymutilcmd}"
            COMMAND_EXPAND_LISTS
            BYPRODUCTS Code_Gen_Model.dwarf)
endif()


######################################################################
## Target install and export rules
######################################################################
install(TARGETS Code_Gen_Model_objects EXPORT Code_Gen_ModelTargets OBJECTS DESTINATION Code_Gen_Model_ert_rtw)
install(TARGETS Code_Gen_Model RUNTIME DESTINATION . OPTIONAL)
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    install(FILES $<TARGET_FILE_DIR:Code_Gen_Model>/Code_Gen_Model.dwarf DESTINATION . OPTIONAL CONFIGURATIONS Debug RelWithDebInfo)
endif()
if(CMAKE_C_LINKER_SUPPORTS_PDB)
    install(FILES $<TARGET_PDB_FILE:Code_Gen_Model> DESTINATION . OPTIONAL CONFIGURATIONS Debug RelWithDebInfo)
endif()
install(EXPORT Code_Gen_ModelTargets NAMESPACE Code_Gen_Model:: DESTINATION Code_Gen_Model_ert_rtw/export)
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/Code_Gen_Model.cmake 
 "include(\"\${CMAKE_CURRENT_LIST_DIR}/Code_Gen_ModelTargets.cmake\")" \n
    "target_include_directories(Code_Gen_Model::Code_Gen_Model_objects INTERFACE \n"
    "    \${MATLAB_ROOT}/extern/include" \n 
    "    \${MATLAB_ROOT}/simulink/include" \n 
    "    \${MATLAB_ROOT}/rtw/c/src" \n 
    "    \${MATLAB_ROOT}/rtw/c/src/ext_mode/common" \n 
    "    \${MATLAB_ROOT}/rtw/c/ert)" \n )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Code_Gen_Model.cmake DESTINATION Code_Gen_Model_ert_rtw/export)

######################################################################
## Build success message
######################################################################
add_custom_command(TARGET Code_Gen_Model POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created executable: $<TARGET_FILE:Code_Gen_Model>")

######################################################################
## Call toolchain hook function if defined
######################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(Code_Gen_Model)
endif()
