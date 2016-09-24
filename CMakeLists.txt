cmake_minimum_required (VERSION 3.1.0 FATAL_ERROR)
project (PrefixScript)
execute_process(COMMAND "../getversion.pl" OUTPUT_VARIABLE PrefixScript_VERSION)
set (PrefixScript_MINCOMP 0.017)
configure_file (
    "${PROJECT_SOURCE_DIR}/versioninfo.h.in"
    "${PROJECT_SOURCE_DIR}/versioninfo.h"
)
configure_file (
    "${PROJECT_SOURCE_DIR}/doc.js.in"
    "${PROJECT_SOURCE_DIR}/doc.js"
)
include_directories("${PROJECT_BINARY_DIR}")
add_executable(prefixscript main.cc)
set_property(TARGET prefixscript PROPERTY CXX_STANDARD 11)
set_property(TARGET prefixscript PROPERTY CXX_STANDARD_REQUIRED ON)
install (TARGETS prefixscript DESTINATION bin)
enable_testing()
add_test(quicktest ./prefixscript ../testsuite.presc)
set_tests_properties(quicktest PROPERTIES PASS_REGULAR_EXPRESSION "20 of 20 tests passed")
