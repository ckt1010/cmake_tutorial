cmake_minimum_required(VERSION 3.10)

project(step2 VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYMATH "Use step2 math" ON)

configure_file(step2.h.in step2.h)
add_executable(step2 step2.cpp)

if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif(USE_MYMATH)

target_link_libraries(step2 PUBLIC ${EXTRA_LIBS})
target_include_directories(step2 PUBLIC 
                          "${PROJECT_BINARY_DIR}"
                          ${EXTRA_INCLUDES}
                          )