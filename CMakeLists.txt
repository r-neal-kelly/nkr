cmake_minimum_required(VERSION 3.23)

# Commonly needed directories
set(NKR_BUILD_DIR "${CMAKE_BINARY_DIR}")
set(NKR_BUILD_LIB_DIR "${NKR_BUILD_DIR}/lib")
set(NKR_BUILD_BIN_DIR "${NKR_BUILD_DIR}/bin")

set(NKR_DIR "${CMAKE_SOURCE_DIR}")

set(NKR_NKR_DIR "${NKR_DIR}/nkr")
set(NKR_NKR_INCLUDE_DIR "${NKR_NKR_DIR}/include")
set(NKR_NKR_SOURCE_DIR "${NKR_NKR_DIR}/src")

set(NKR_DOCTEST_DIR "${NKR_DIR}/doctest")
set(NKR_DOCTEST_INCLUDE_DIR "${NKR_DOCTEST_DIR}/include")
set(NKR_DOCTEST_SOURCE_DIR "${NKR_DOCTEST_DIR}/src")

# All libraries go in one folder and all executables in another.
# This applies to all libraries and executables in this project.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${NKR_BUILD_LIB_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${NKR_BUILD_BIN_DIR}")

project(nkr
        LANGUAGES CXX)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

add_subdirectory("./nkr")

#if (BUILD_TESTING)
    add_subdirectory("./doctest")
    add_subdirectory("./nkr_tests/boolean")
    add_subdirectory("./nkr_tests/generic")
#endif()

# Just some helpful console ouput
message("-- Will build from source at: ${NKR_DIR}")
message("-- Will produce archives at: ${NKR_BUILD_LIB_DIR}")
message("-- Will produce executables at: ${NKR_BUILD_BIN_DIR}")
