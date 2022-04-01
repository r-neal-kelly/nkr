cmake_minimum_required(VERSION 3.18)

project(nkr
        LANGUAGES CXX)

include(CheckCXXCompilerFlag)

# Commonly needed directories
set(NKR_BUILD_DIR "${CMAKE_BINARY_DIR}")
set(NKR_BUILD_LIB_DIR "${NKR_BUILD_DIR}/lib")
set(NKR_BUILD_BIN_DIR "${NKR_BUILD_DIR}/bin")

set(NKR_DIR "${CMAKE_SOURCE_DIR}")
set(NKR_NKR_DIR "${NKR_DIR}/nkr")
set(NKR_NKR_INCLUDE_DIR "${NKR_NKR_DIR}/include")
set(NKR_DOCTEST_DIR "${NKR_DIR}/doctest")
set(NKR_DOCTEST_INCLUDE_DIR "${NKR_DOCTEST_DIR}/include")

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

# We need to check if certain flags are available and set them if so
function(try_add_compile_options OPTIONS)
    foreach(OPTION ${OPTIONS})
        unset(HAS_COMPILER_OPTION CACHE)
        check_cxx_compiler_flag("${OPTION}" HAS_COMPILER_OPTION)
        if (HAS_COMPILER_OPTION)
            add_compile_options("${OPTION}")
            message("---- Added compile option: ${OPTION}")
        else()
            add_compile_options("${OPTION}")
            message("---- Forcibly added compile option: ${OPTION}")
        endif()
    endforeach()
endfunction()

# for some reason, CMake is failing to identity valid compile options.
# could be because a previous option was already set? Need to experiment.
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    try_add_compile_options("/std:c++latest"
                            "/std:c17"
                            "/W3"
                            "/volatile:iso"
                            "/bigobj")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if (DEFINED ENV{nkr_IS_32_BIT})
        try_add_compile_options("-m32")
    elseif (DEFINED ENV{nkr_IS_64_BIT})
        try_add_compile_options("-m64")
    endif()
    try_add_compile_options("-fmax-errors=1")
endif()

add_subdirectory("nkr")

if (DEFINED ENV{nkr_DO_GENERATE_TESTS})
    add_subdirectory("doctest")
    add_subdirectory("nkr_tests/allocator")
    add_subdirectory("nkr_tests/array")
    add_subdirectory("nkr_tests/atomic_t")
    add_subdirectory("nkr_tests/boolean")
    add_subdirectory("nkr_tests/charcoder")
    add_subdirectory("nkr_tests/concurrency")
    add_subdirectory("nkr_tests/constant")
    add_subdirectory("nkr_tests/cpp")
    add_subdirectory("nkr_tests/docs")
    add_subdirectory("nkr_tests/enumeration")
    add_subdirectory("nkr_tests/generic")
    add_subdirectory("nkr_tests/hasher")
    add_subdirectory("nkr_tests/interface")
    add_subdirectory("nkr_tests/macros")
    add_subdirectory("nkr_tests/math")
    add_subdirectory("nkr_tests/maybe_t")
    add_subdirectory("nkr_tests/negatable")
    add_subdirectory("nkr_tests/none")
    add_subdirectory("nkr_tests/number")
    add_subdirectory("nkr_tests/optional")
    add_subdirectory("nkr_tests/os")
    add_subdirectory("nkr_tests/pointer")
    add_subdirectory("nkr_tests/pointer_t")
    add_subdirectory("nkr_tests/positive")
    add_subdirectory("nkr_tests/randomness")
    add_subdirectory("nkr_tests/regex_t")
    add_subdirectory("nkr_tests/string")
    add_subdirectory("nkr_tests/tr")
    add_subdirectory("nkr_tests/tree")
    add_subdirectory("nkr_tests/tuple")
    add_subdirectory("nkr_tests/utils")
endif()

# Just some helpful console ouput
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message("---- Configuring for MSVC...")
endif()
message("---- Generating configuration from source at: ${NKR_DIR}")
message("---- Archives will be available at: ${NKR_BUILD_LIB_DIR}")
message("---- Executables will be available at: ${NKR_BUILD_BIN_DIR}")
