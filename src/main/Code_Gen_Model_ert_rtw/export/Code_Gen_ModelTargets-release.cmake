#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Code_Gen_Model::Code_Gen_Model_objects" for configuration "Release"
set_property(TARGET Code_Gen_Model::Code_Gen_Model_objects APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Code_Gen_Model::Code_Gen_Model_objects PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_OBJECTS_RELEASE "${_IMPORT_PREFIX}/Code_Gen_Model_ert_rtw/objects-Release/Code_Gen_Model_objects/Code_Gen_Model.c.obj"
  )

list(APPEND _IMPORT_CHECK_TARGETS Code_Gen_Model::Code_Gen_Model_objects )
list(APPEND _IMPORT_CHECK_FILES_FOR_Code_Gen_Model::Code_Gen_Model_objects "${_IMPORT_PREFIX}/Code_Gen_Model_ert_rtw/objects-Release/Code_Gen_Model_objects/Code_Gen_Model.c.obj" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
