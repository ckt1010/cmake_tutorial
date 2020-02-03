cmake_minimum_required(VERSION 3.10)

project(step6 VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYMATH "Use step6 math" ON)

configure_file(step6.h.in step6.h)
add_executable(step6 step6.cpp)

if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    target_compile_definitions(MathFunctions PUBLIC "USE_MYMATH")
endif(USE_MYMATH)

target_link_libraries(step6 PUBLIC ${EXTRA_LIBS})
target_include_directories(step6 PUBLIC 
                          "${PROJECT_BINARY_DIR}"
                          )

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${step6_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${step6_VERSION_MINOR}")
include(CPack)

# enable dashboard scripting
include(CTest)

set(CTEST_PROJECT_NAME "CMakeTutorial")
set(CTEST_NIGHTLY_START_TIME "00:00:00 EST")

set(CTEST_DROP_METHOD "http")
set(CTEST_DROP_SITE "my.cdash.org")
set(CTEST_DROP_LOCATION "/submit.php?project=CMakeTutorial")
set(CTEST_DROP_SITE_CDASH TRUE)

add_test(NAME RunsStep6 COMMAND step6 25)

add_test(NAME Usage COMMAND step6)
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
  )

# define a function to simplify adding tests
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction(do_test)

# do a bunch of result based tests
do_test(step6 4 "4 is 2")
do_test(step6 9 "9 is 3")
do_test(step6 5 "5 is 2.236")
do_test(step6 7 "7 is 2.645")
do_test(step6 25 "25 is 5")
do_test(step6 -25 "-25 is [-nan|nan|0]")
do_test(step6 0.0001 "0.0001 is 0.01")