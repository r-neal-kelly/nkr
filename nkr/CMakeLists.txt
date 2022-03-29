cmake_minimum_required(VERSION 3.23)

project(nkr
        LANGUAGES CXX)

include("CMakeLists_Funcs.cmake")

get_include_files(THIS_INCLUDE_FILES)
get_source_files(THIS_SOURCE_FILES)

add_library(nkr STATIC)
target_sources(nkr PUBLIC ${THIS_INCLUDE_FILES})
target_sources(nkr PRIVATE ${THIS_SOURCE_FILES})

target_include_directories(nkr
                           PUBLIC "${NKR_NKR_INCLUDE_DIR}")

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
             PREFIX "File Tree"
             FILES ${THIS_INCLUDE_FILES} ${THIS_SOURCE_FILES})
