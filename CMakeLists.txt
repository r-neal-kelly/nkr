cmake_minimum_required(VERSION 3.18)

execute_process(COMMAND "node" "${CMAKE_SOURCE_DIR}/tools/make_cmake_lists" "${CMAKE_SOURCE_DIR}")
execute_process(COMMAND "node" "${CMAKE_SOURCE_DIR}/tools/add_include_guards" "${CMAKE_SOURCE_DIR}")

project(nkr
        LANGUAGES CXX)
        
# Commonly needed directories
set(NKR_BUILD_LIB_DIR "${CMAKE_BINARY_DIR}/lib")
set(NKR_BUILD_BIN_DIR "${CMAKE_BINARY_DIR}/bin")
set(NKR_NKR_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/nkr/include")
set(NKR_DOCTEST_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/doctest/include")

# All libraries go in one folder and all executables in another.
# This applies to all libraries and executables in this project.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${NKR_BUILD_LIB_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${NKR_BUILD_BIN_DIR}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Definitions for all nkr targets
if (DEFINED ENV{nkr_IS_WINDOWS})
    add_compile_definitions(nkr_IS_WINDOWS)
elseif (DEFINED ENV{nkr_IS_LINUX})
    add_compile_definitions(nkr_IS_LINUX)
endif()

if (DEFINED ENV{nkr_IS_32_BIT})
    add_compile_definitions(nkr_IS_32_BIT)
elseif (DEFINED ENV{nkr_IS_64_BIT})
    add_compile_definitions(nkr_IS_64_BIT)
endif()

add_compile_definitions(
    $<$<CONFIG:Debug>:nkr_IS_DEBUG>
    $<$<CONFIG:Release>:nkr_IS_RELEASE>
    $<$<CONFIG:RelWithDebInfo>:nkr_IS_DEBUG>
    $<$<CONFIG:MinSizeRel>:nkr_IS_RELEASE>
)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options("/std:c++latest")
    add_compile_options("/W3")
    add_compile_options("/volatile:iso")
    add_compile_options("/bigobj")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if (DEFINED ENV{nkr_IS_32_BIT})
        add_compile_options("-m32")
    elseif (DEFINED ENV{nkr_IS_64_BIT})
        add_compile_options("-m64")
    endif()
    add_compile_options("-pedantic")
    add_compile_options("-w")
    add_compile_options("-fmax-errors=4")
    add_compile_options("-Wno-volatile")
endif()

add_subdirectory("nkr")
if (DEFINED ENV{nkr_DO_GENERATE_TESTS})
    add_subdirectory("doctest")
    add_subdirectory("nkr_tests")
endif()

message("-- Generating configuration from source at: ${CMAKE_SOURCE_DIR}")
message("-- Archives will be available at: ${NKR_BUILD_LIB_DIR}")
message("-- Executables will be available at: ${NKR_BUILD_BIN_DIR}")
