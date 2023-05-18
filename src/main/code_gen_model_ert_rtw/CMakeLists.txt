######################################################################
# CMakeLists.txt generated for component code_gen_model
# Product type: executable
######################################################################
cmake_minimum_required(VERSION 3.12)
project(code_gen_model)
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
set(CODE_GEN_MODEL_COMMON_DEFINES -DMODEL=code_gen_model
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
    -DMULTI_INSTANCE_CODE=1
    -DINTEGER_CODE=0
    -DMT=0
    -D_CRT_SECURE_NO_WARNINGS)

set(CODE_GEN_MODEL_COMMON_COMPILER_FLAGS /wd4251
    -EHs)

add_library(code_gen_model_objects OBJECT ${START_DIR}/code_gen_model_ert_rtw/code_gen_model.cpp
    ${START_DIR}/code_gen_model_ert_rtw/code_gen_model_data.cpp
    ${START_DIR}/code_gen_model_ert_rtw/rtGetInf.cpp
    ${START_DIR}/code_gen_model_ert_rtw/rtGetNaN.cpp
    ${START_DIR}/code_gen_model_ert_rtw/rt_nonfinite.cpp)
set_target_properties(code_gen_model_objects PROPERTIES
    PREFIX ""
    POSITION_INDEPENDENT_CODE ON)
target_compile_features(code_gen_model_objects PUBLIC cxx_std_11)
target_compile_definitions(code_gen_model_objects PRIVATE ${CODE_GEN_MODEL_COMMON_DEFINES})
target_compile_options(code_gen_model_objects PRIVATE ${CODE_GEN_MODEL_COMMON_COMPILER_FLAGS})
target_include_directories(code_gen_model_objects PUBLIC $<BUILD_INTERFACE:${START_DIR}>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>>
    $<BUILD_INTERFACE:${START_DIR}/code_gen_model_ert_rtw>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/code_gen_model_ert_rtw>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/extern/include>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/simulink/include>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/src>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/src/ext_mode/common>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/ert>)
target_link_libraries(code_gen_model_objects PUBLIC $<$<BOOL:${FOUND_LIBM}>:m>)

add_executable(code_gen_model  ${START_DIR}/code_gen_model_ert_rtw/ert_main.cpp)
set_target_properties(code_gen_model PROPERTIES
    PREFIX ""
    POSITION_INDEPENDENT_CODE ON)
target_compile_features(code_gen_model PUBLIC cxx_std_11)
target_compile_definitions(code_gen_model PRIVATE ${CODE_GEN_MODEL_COMMON_DEFINES})
target_compile_options(code_gen_model PRIVATE ${CODE_GEN_MODEL_COMMON_COMPILER_FLAGS})
target_link_libraries(code_gen_model PRIVATE code_gen_model_objects)
if(WIN32)
   target_link_libraries(code_gen_model PRIVATE kernel32
       ws2_32
       mswsock
       advapi32)
endif()

######################################################################
## Extract debug symbols
######################################################################
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    string(APPEND _dsymutilcmd "$<IF:$<CONFIG:DEBUG,RELWITHDEBINFO>,"
                "xcrun;dsymutil;$<TARGET_FILE:code_gen_model>;--flat,"
                "true"
        >)
    add_custom_command(TARGET code_gen_model
            POST_BUILD
            COMMAND "${_dsymutilcmd}"
            COMMAND_EXPAND_LISTS
            BYPRODUCTS code_gen_model.dwarf)
endif()


######################################################################
## Target install and export rules
######################################################################
install(TARGETS code_gen_model_objects EXPORT code_gen_modelTargets OBJECTS DESTINATION code_gen_model_ert_rtw)
install(TARGETS code_gen_model RUNTIME DESTINATION . OPTIONAL)
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    install(FILES $<TARGET_FILE_DIR:code_gen_model>/code_gen_model.dwarf DESTINATION . OPTIONAL CONFIGURATIONS Debug RelWithDebInfo)
endif()
if(CMAKE_C_LINKER_SUPPORTS_PDB)
    install(FILES $<TARGET_PDB_FILE:code_gen_model> DESTINATION . OPTIONAL CONFIGURATIONS Debug RelWithDebInfo)
endif()
install(EXPORT code_gen_modelTargets NAMESPACE code_gen_model:: DESTINATION code_gen_model_ert_rtw/export)
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/code_gen_model.cmake 
 "include(\"\${CMAKE_CURRENT_LIST_DIR}/code_gen_modelTargets.cmake\")" \n
    "target_include_directories(code_gen_model::code_gen_model_objects INTERFACE \n"
    "    \${MATLAB_ROOT}/extern/include" \n 
    "    \${MATLAB_ROOT}/simulink/include" \n 
    "    \${MATLAB_ROOT}/rtw/c/src" \n 
    "    \${MATLAB_ROOT}/rtw/c/src/ext_mode/common" \n 
    "    \${MATLAB_ROOT}/rtw/c/ert)" \n )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/code_gen_model.cmake DESTINATION code_gen_model_ert_rtw/export)

######################################################################
## Build success message
######################################################################
add_custom_command(TARGET code_gen_model POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created executable: $<TARGET_FILE:code_gen_model>")

######################################################################
## Call toolchain hook function if defined
######################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(code_gen_model)
endif()
