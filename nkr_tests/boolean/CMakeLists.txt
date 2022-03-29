cmake_minimum_required(VERSION 3.23)

include("CMakeLists_Sources.cmake")

project(nkr_test_boolean
        LANGUAGES CXX)

add_executable(nkr_test_boolean)

add_target_includes(nkr_test_boolean)
add_target_sources(nkr_test_boolean)

target_include_directories(nkr_test_boolean
                           PRIVATE "${NKR_NKR_INCLUDE_DIR}"
                           PRIVATE "${NKR_DOCTEST_INCLUDE_DIR}")

target_link_libraries(nkr_test_boolean
                      PRIVATE nkr
                      PRIVATE doctest)

target_compile_features(nkr_test_boolean
                        PRIVATE cxx_std_20)

# target_compile_options for compiler options (we'll want to use private for our exe and
# public for the libs. public adds it to INTERFACE usage req, making it added to any exec, I think)

# target_compile_definitions for preprocessor defs

# add_compile_options for everything in this directory and below
