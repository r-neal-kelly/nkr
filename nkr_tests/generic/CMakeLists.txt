cmake_minimum_required(VERSION 3.23)

include("CMakeLists_Sources.cmake")

project(nkr_test_generic
        LANGUAGES CXX)

add_executable(nkr_test_generic)

add_target_includes(nkr_test_generic)
add_target_sources(nkr_test_generic)

target_include_directories(nkr_test_generic
                           PRIVATE "${NKR_NKR_INCLUDE_DIR}"
                           PRIVATE "${NKR_DOCTEST_INCLUDE_DIR}")

target_link_libraries(nkr_test_generic
                      PRIVATE nkr
                      PRIVATE doctest)
