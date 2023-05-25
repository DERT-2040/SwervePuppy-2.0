include("${CMAKE_CURRENT_LIST_DIR}/Code_Gen_ModelTargets.cmake")
target_include_directories(Code_Gen_Model::Code_Gen_Model_objects INTERFACE 
    ${MATLAB_ROOT}/extern/include
    ${MATLAB_ROOT}/simulink/include
    ${MATLAB_ROOT}/rtw/c/src
    ${MATLAB_ROOT}/rtw/c/src/ext_mode/common
    ${MATLAB_ROOT}/rtw/c/ert)
