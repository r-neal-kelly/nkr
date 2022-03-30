# nkr_test_tr

cmake_minimum_required(VERSION 3.23)

project(nkr_test_tr
        LANGUAGES CXX)

set(THIS_INCLUDE_FILES
    "")

set(THIS_SOURCE_FILES
    "src/tr.cpp")

add_executable(nkr_test_tr)
target_sources(nkr_test_tr PUBLIC ${THIS_INCLUDE_FILES})
target_sources(nkr_test_tr PRIVATE ${THIS_SOURCE_FILES})

target_include_directories(nkr_test_tr
                           PRIVATE "${NKR_NKR_INCLUDE_DIR}"
                           PRIVATE "${NKR_DOCTEST_INCLUDE_DIR}"
                           PRIVATE "include")

target_link_libraries(nkr_test_tr
                      PRIVATE nkr
                      PRIVATE doctest)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
             PREFIX "File Tree"
             FILES ${THIS_INCLUDE_FILES} ${THIS_SOURCE_FILES})
