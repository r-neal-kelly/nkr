cmake_minimum_required(VERSION 3.23)

project(doctest
        LANGUAGES CXX)

include("CMakeLists_Sources.cmake")

add_library(doctest STATIC)

add_target_includes(doctest)
add_target_sources(doctest)

target_include_directories(doctest
                           PUBLIC "${NKR_DOCTEST_INCLUDE_DIR}")
