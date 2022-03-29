cmake_minimum_required(VERSION 3.23)

include("CMakeLists_Sources.cmake")

project(doctest
        LANGUAGES CXX)

add_library(doctest STATIC)

add_target_includes(doctest)
add_target_sources(doctest)

target_include_directories(doctest
                           PUBLIC "${NKR_DOCTEST_INCLUDE_DIR}")

target_compile_features(doctest
                        PUBLIC cxx_std_20)
