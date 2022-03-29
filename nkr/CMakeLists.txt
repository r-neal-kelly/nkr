cmake_minimum_required(VERSION 3.23)

project(nkr
        LANGUAGES CXX)

include("CMakeLists_Sources.cmake")

add_library(nkr STATIC)

add_target_includes(nkr)
add_target_sources(nkr)

target_include_directories(nkr
                           PUBLIC "${NKR_NKR_INCLUDE_DIR}")
