# nkr_test_array

cmake_minimum_required(VERSION 3.18)

project(nkr_test_array
        LANGUAGES CXX)

set(THIS_INCLUDE_FILES
    "")

set(THIS_SOURCE_FILES
    "src/cpp_t.cpp"
    "src/local/dynamic_t.cpp"
    "src/local/static_t.cpp")

add_executable(nkr_test_array)
target_sources(nkr_test_array PUBLIC ${THIS_INCLUDE_FILES})
target_sources(nkr_test_array PRIVATE ${THIS_SOURCE_FILES})

target_include_directories(nkr_test_array
                           PRIVATE "${NKR_NKR_INCLUDE_DIR}"
                           PRIVATE "${NKR_DOCTEST_INCLUDE_DIR}"
                           PRIVATE "include")

target_link_libraries(nkr_test_array
                      PRIVATE nkr
                      PRIVATE doctest)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
             PREFIX "File Tree"
             FILES ${THIS_INCLUDE_FILES} ${THIS_SOURCE_FILES})
