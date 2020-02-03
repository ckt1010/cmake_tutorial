cmake_minimum_required(VERSION 3.10)

project(step3 VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYMATH "Use step3 math" ON)

configure_file(step3.h.in step3.h)
add_executable(step3 step3.cpp)

if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    target_compile_definitions(MathFunctions PUBLIC "USE_MYMATH")
endif(USE_MYMATH)

target_link_libraries(step3 PUBLIC ${EXTRA_LIBS})
target_include_directories(step3 PUBLIC 
                          "${PROJECT_BINARY_DIR}"
                          )

install(TARGETS step3 DESTINATION lib)
install(FILES "${PROJECT_BINARY_DIR}/step3.h" DESTINATION include)

enable_testing()

add_test(NAME RunsStep3 COMMAND step3 25)

add_test(NAME Usage COMMAND step3)
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
do_test(step3 4 "4 is 2")
do_test(step3 9 "9 is 3")
do_test(step3 5 "5 is 2.236")
do_test(step3 7 "7 is 2.645")
do_test(step3 25 "25 is 5")
do_test(step3 -25 "-25 is [-nan|nan|0]")
do_test(step3 0.0001 "0.0001 is 0.01")