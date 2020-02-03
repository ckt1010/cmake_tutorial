add_library(MathFunctions MathFunctions.cpp)
# target_include_directories(MathFunctions
#           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
#           )
target_include_directories(MathFunctions
          INTERFACE
           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
           $<INSTALL_INTERFACE:include>
          )
option(USE_MYMATH "Use my math" OFF)
if(USE_MYMATH)
    add_executable(MakeTable MakeTable.cpp)
    add_custom_command(
      OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
      COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
      DEPENDS MakeTable
      )
    target_compile_definitions(MathFunctions PUBLIC "USE_MYMATH")

    # library that just does sqrt
    add_library(SqrtLibrary STATIC
                mysqrt.cpp
                ${CMAKE_CURRENT_BINARY_DIR}/Table.h
                )

    # state that we depend on our binary dir to find Table.h
    target_include_directories(SqrtLibrary PRIVATE
                ${CMAKE_CURRENT_BINARY_DIR}
                )
    set_target_properties(SqrtLibrary PROPERTIES
                          POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                          )
    target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif(USE_MYMATH)

install(TARGETS MathFunctions DESTINATION lib EXPORT MathFunctionsTargets)
install(FILES MathFunctions.h DESTINATION include)

