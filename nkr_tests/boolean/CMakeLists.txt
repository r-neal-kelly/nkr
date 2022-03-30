# nkr_test_boolean

cmake_minimum_required(VERSION 3.23)

project(nkr_test_boolean
        LANGUAGES CXX)

set(THIS_INCLUDE_FILES
    "")

set(THIS_SOURCE_FILES
    "src/bool_t.cpp"
    "src/cpp_t.cpp"
    "src/pure_t.cpp")

add_executable(nkr_test_boolean)
target_sources(nkr_test_boolean PUBLIC ${THIS_INCLUDE_FILES})
target_sources(nkr_test_boolean PRIVATE ${THIS_SOURCE_FILES})

target_include_directories(nkr_test_boolean
                           PRIVATE "${NKR_NKR_INCLUDE_DIR}"
                           PRIVATE "${NKR_DOCTEST_INCLUDE_DIR}"
                           PRIVATE "include")

target_link_libraries(nkr_test_boolean
                      PRIVATE nkr
                      PRIVATE doctest)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
             PREFIX "File Tree"
             FILES ${THIS_INCLUDE_FILES} ${THIS_SOURCE_FILES})
