# nkr_test_pointer

cmake_minimum_required(VERSION 3.21)

project(nkr_test_pointer
        LANGUAGES CXX)

set(THIS_INCLUDE_FILES
    "")

set(THIS_SOURCE_FILES
    "src/cpp_t.cpp")

add_executable(nkr_test_pointer)
target_sources(nkr_test_pointer PUBLIC ${THIS_INCLUDE_FILES})
target_sources(nkr_test_pointer PRIVATE ${THIS_SOURCE_FILES})

target_include_directories(nkr_test_pointer
                           PRIVATE "${NKR_NKR_INCLUDE_DIR}"
                           PRIVATE "${NKR_DOCTEST_INCLUDE_DIR}"
                           PRIVATE "include")

target_link_libraries(nkr_test_pointer
                      PRIVATE nkr
                      PRIVATE doctest)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
             PREFIX "File Tree"
             FILES ${THIS_INCLUDE_FILES} ${THIS_SOURCE_FILES})
