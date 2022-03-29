cmake_minimum_required(VERSION 3.23)

project(doctest
        LANGUAGES CXX)

include("CMakeLists_Funcs.cmake")

get_include_files(THIS_INCLUDE_FILES)
get_source_files(THIS_SOURCE_FILES)

add_library(doctest STATIC)
target_sources(doctest PUBLIC ${THIS_INCLUDE_FILES})
target_sources(doctest PRIVATE ${THIS_SOURCE_FILES})

target_include_directories(doctest
                           PUBLIC "${NKR_DOCTEST_INCLUDE_DIR}")

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
             PREFIX "File Tree"
             FILES ${THIS_INCLUDE_FILES} ${THIS_SOURCE_FILES})
