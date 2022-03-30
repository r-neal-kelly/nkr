# doctest

cmake_minimum_required(VERSION 3.21)

project(doctest
        LANGUAGES CXX)

set(THIS_INCLUDE_FILES
    "include/doctest.h")

set(THIS_SOURCE_FILES
    "src/doctest.cpp")

add_library(doctest STATIC)
target_sources(doctest PUBLIC ${THIS_INCLUDE_FILES})
target_sources(doctest PRIVATE ${THIS_SOURCE_FILES})

target_include_directories(doctest
                           PUBLIC "include")

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
             PREFIX "File Tree"
             FILES ${THIS_INCLUDE_FILES} ${THIS_SOURCE_FILES})
