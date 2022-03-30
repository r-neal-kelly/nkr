# nkr_test_maybe_t

cmake_minimum_required(VERSION 3.21)

project(nkr_test_maybe_t
        LANGUAGES CXX)

set(THIS_INCLUDE_FILES
    "")

set(THIS_SOURCE_FILES
    "src/maybe_t_built_in_sp.cpp"
    "src/maybe_t_user_defined_sp.cpp"
    "src/none_t.cpp"
    "src/some_t.cpp")

add_executable(nkr_test_maybe_t)
target_sources(nkr_test_maybe_t PUBLIC ${THIS_INCLUDE_FILES})
target_sources(nkr_test_maybe_t PRIVATE ${THIS_SOURCE_FILES})

target_include_directories(nkr_test_maybe_t
                           PRIVATE "${NKR_NKR_INCLUDE_DIR}"
                           PRIVATE "${NKR_DOCTEST_INCLUDE_DIR}"
                           PRIVATE "include")

target_link_libraries(nkr_test_maybe_t
                      PRIVATE nkr
                      PRIVATE doctest)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
             PREFIX "File Tree"
             FILES ${THIS_INCLUDE_FILES} ${THIS_SOURCE_FILES})
