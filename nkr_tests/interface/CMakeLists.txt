# nkr_test_interface

cmake_minimum_required(VERSION 3.21)

project(nkr_test_interface
        LANGUAGES CXX)

set(THIS_INCLUDE_FILES
    "")

set(THIS_SOURCE_FILES
    "src/enumeration/types_i.cpp"
    "src/none/value_i.cpp"
    "src/randomness/value_i.cpp"
    "src/template_i.cpp"
    "src/type_i.cpp")

add_executable(nkr_test_interface)
target_sources(nkr_test_interface PUBLIC ${THIS_INCLUDE_FILES})
target_sources(nkr_test_interface PRIVATE ${THIS_SOURCE_FILES})

target_include_directories(nkr_test_interface
                           PRIVATE "${NKR_NKR_INCLUDE_DIR}"
                           PRIVATE "${NKR_DOCTEST_INCLUDE_DIR}"
                           PRIVATE "include")

target_link_libraries(nkr_test_interface
                      PRIVATE nkr
                      PRIVATE doctest)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
             PREFIX "File Tree"
             FILES ${THIS_INCLUDE_FILES} ${THIS_SOURCE_FILES})
