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

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# We need to check if certain flags are available and set them if so
unset(NKR_COMPILER_HAS_STD_CPP_LATEST CACHE)
check_cxx_compiler_flag("/std:c++latest" NKR_COMPILER_HAS_STD_CPP_LATEST)
if (NKR_COMPILER_HAS_STD_CPP_LATEST)
    add_compile_options("/std:c++latest")
endif()

unset(NKR_COMPILER_HAS_STD_C17 CACHE)
check_cxx_compiler_flag("/std:c17" NKR_COMPILER_HAS_STD_C17)
if (NKR_COMPILER_HAS_STD_C17)
    add_compile_options("/std:c17")
endif()

unset(NKR_COMPILER_HAS_W3 CACHE)
check_cxx_compiler_flag("/W3" NKR_COMPILER_HAS_W3)
if (NKR_COMPILER_HAS_W3)
    add_compile_options("/W3")
endif()

unset(NKR_COMPILER_HAS_VOLATILE_ISO CACHE)
check_cxx_compiler_flag("/volatile:iso" NKR_COMPILER_HAS_VOLATILE_ISO)
if (NKR_COMPILER_HAS_VOLATILE_ISO)
    add_compile_options("/volatile:iso")
endif()

unset(NKR_COMPILER_HAS_BIGOBJ CACHE)
check_cxx_compiler_flag("/bigobj" NKR_COMPILER_HAS_BIGOBJ)
if (NKR_COMPILER_HAS_BIGOBJ)
    add_compile_options("/bigobj")
endif()

add_subdirectory("nkr")

if (DEFINED ENV{NKR_GENERATE_TESTS})
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
