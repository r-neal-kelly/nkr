# nkr_test_tree

cmake_minimum_required(VERSION 3.23)

project(nkr_test_tree
        LANGUAGES CXX)

include("CMakeLists_Funcs.cmake")

get_include_files(THIS_INCLUDE_FILES)
get_source_files(THIS_SOURCE_FILES)

add_executable(nkr_test_tree)
target_sources(nkr_test_tree PUBLIC ${THIS_INCLUDE_FILES})
target_sources(nkr_test_tree PRIVATE ${THIS_SOURCE_FILES})

target_include_directories(nkr_test_tree
                           PRIVATE "${NKR_NKR_INCLUDE_DIR}"
                           PRIVATE "${NKR_DOCTEST_INCLUDE_DIR}"
                           PRIVATE "include")

target_link_libraries(nkr_test_tree
                      PRIVATE nkr
                      PRIVATE doctest)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
             PREFIX "File Tree"
             FILES ${THIS_INCLUDE_FILES} ${THIS_SOURCE_FILES})
