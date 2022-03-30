# nkr_test_charcoder

cmake_minimum_required(VERSION 3.21)

project(nkr_test_charcoder
        LANGUAGES CXX)

set(THIS_INCLUDE_FILES
    "include/unicode.h")

set(THIS_SOURCE_FILES
    "src/ascii_t.cpp"
    "src/utf_16_t.cpp"
    "src/utf_32_t.cpp"
    "src/utf_8_t.cpp")

add_executable(nkr_test_charcoder)
target_sources(nkr_test_charcoder PUBLIC ${THIS_INCLUDE_FILES})
target_sources(nkr_test_charcoder PRIVATE ${THIS_SOURCE_FILES})

target_include_directories(nkr_test_charcoder
                           PRIVATE "${NKR_NKR_INCLUDE_DIR}"
                           PRIVATE "${NKR_DOCTEST_INCLUDE_DIR}"
                           PRIVATE "include")

target_link_libraries(nkr_test_charcoder
                      PRIVATE nkr
                      PRIVATE doctest)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
             PREFIX "File Tree"
             FILES ${THIS_INCLUDE_FILES} ${THIS_SOURCE_FILES})
