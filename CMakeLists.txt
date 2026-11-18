cmake_minimum_required(VERSION 3.16)
project(arraylib VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Keep produced executables and shared library together.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

add_library(arraylib SHARED src/arraylib.cpp)
target_include_directories(arraylib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_definitions(arraylib PRIVATE ARRAYLIB_BUILD)

add_library(arraylib_static STATIC src/arraylib.cpp)
target_include_directories(arraylib_static PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_definitions(arraylib_static PUBLIC ARRAYLIB_STATIC)
set_target_properties(arraylib_static PROPERTIES OUTPUT_NAME arraylib)

foreach(target IN ITEMS arraylib arraylib_static)
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endforeach()

add_executable(app main.cpp)
target_link_libraries(app PRIVATE arraylib)

add_executable(variant_07 examples/variant_07.cpp)
target_link_libraries(variant_07 PRIVATE arraylib)

# Let Linux find the .so next to the executable.
if(UNIX AND NOT APPLE)
    set_target_properties(app variant_07 PROPERTIES BUILD_RPATH "$ORIGIN")
endif()

include(CTest)
if(BUILD_TESTING)
    add_executable(test_unit tests/test_unit.cpp)
    target_link_libraries(test_unit PRIVATE arraylib)
    add_executable(test_integration tests/test_integration.cpp)
    target_link_libraries(test_integration PRIVATE arraylib)

    if(MSVC)
        # Assertions are disabled in Release under _DEBUG? Use /UNDEBUG here.
        target_compile_options(test_unit PRIVATE /UNDEBUG)
        target_compile_options(test_integration PRIVATE /UNDEBUG)
    else()
        target_compile_options(test_unit PRIVATE -UNDEBUG)
        target_compile_options(test_integration PRIVATE -UNDEBUG)
    endif()

    add_test(NAME unit COMMAND test_unit)
    add_test(NAME integration COMMAND test_integration)
endif()
